from protobuf import Mesh, DataType

import yaml, sys, struct, collada, argparse, datetime, pdb

argparser = argparse.ArgumentParser(description="Extract a mesh from a collada file.")
argparser.add_argument('infile', type=str,
                       help = "The COLLADA file to read from.")
argparser.add_argument('outfile', type=str,
                       help = "The .mesh file to write to:")
argparser.add_argument('--geometry', type=str, metavar = "geometry",
                       required = False, default = 0,
                       help = "Which geometry to read from the COLLADA file (if not specified, the first one)")
argparser.add_argument('--primitive', type=str, metavar = "primitive",
                       required = False, default = 0,
                       help = "Which primitive in the geometry to extract (if not specified, the first one)")
arguments = argparser.parse_args()

input_file = open(arguments.infile, "r")
output_file = open(arguments.outfile, "wb")

collada_data = collada.Collada(input_file)

m = Mesh()

# what attribs do we need?
position_attrib = m.vertexattribs.add()
position_attrib.data_type.type = DataType.TYPE_FLOAT # floating point value
position_attrib.data_type.repeats = 3 # 3D
position_attrib.data_type.bytes_per_repeat = 4 # single-precision float
position_attrib.attrib_type = Mesh.VertexAttrib.ATTRIBTYPE_FLOAT
position_attrib.data = "";
position_attrib.name = "VertexPosition";

colortexture1_uv_attrib = m.vertexattribs.add()
colortexture1_uv_attrib.data_type.type = DataType.TYPE_FLOAT # floating point value
colortexture1_uv_attrib.data_type.repeats = 2 # 2D
colortexture1_uv_attrib.data_type.bytes_per_repeat = 4 # single-precision float
colortexture1_uv_attrib.attrib_type = Mesh.VertexAttrib.ATTRIBTYPE_FLOAT
colortexture1_uv_attrib.data = "";
colortexture1_uv_attrib.name = "ColorTexture1_uv";

# pull our data out of the collada
print collada_data.geometries
prim = collada_data.geometries[arguments.geometry].primitives[arguments.primitive]

# triangulate...
start_triangulating_time = datetime.datetime.now()
print "Triangulating prim {0} in geom {1} in file {2}".format(
    arguments.primitive, arguments.geometry, arguments.infile)
triangulated_prim = prim.triangleset()
end_triangulating_time = datetime.datetime.now()
print "Triangulated 1 prim in {0}ms".format(int((end_triangulating_time - start_triangulating_time).microseconds / 1000))


m.num_vertices = len(triangulated_prim.vertex_index) * 3
print "Writing vertex data for {0} vertices ({1} positions, {2} faces)".format(m.num_vertices, len(triangulated_prim.vertex), len(triangulated_prim.vertex_index))

triangle_num = 0

for vertex_indices, texcoord_indices in zip(triangulated_prim.vertex_index, triangulated_prim.texcoord_indexset[0]):

    # write data for this triangle
    tri = m.triangles.add()
    tri.vert1 = triangle_num*3
    tri.vert2 = (triangle_num*3) + 1
    tri.vert3 = (triangle_num*3) + 2

    for vertex_index, texcoord_index in zip(vertex_indices, texcoord_indices):
        # write POSITION data
        position_attrib.data += (struct.pack("<3f",
                                             triangulated_prim.vertex[vertex_index][0],
                                             triangulated_prim.vertex[vertex_index][1],
                                             triangulated_prim.vertex[vertex_index][2]))

        colortexture1_uv_attrib.data += struct.pack("<2f",
                                                    triangulated_prim.texcoordset[0][texcoord_index][0],
                                                    triangulated_prim.texcoordset[0][texcoord_index][1])
    triangle_num += 1

output_file.write(m.SerializeToString())
output_file.close()
