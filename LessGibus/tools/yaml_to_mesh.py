from protobuf import Mesh, DataType

import yaml, sys, struct

if (len(sys.argv) >= 3):
    infilename = sys.argv[1]
    outfilename = sys.argv[2]
else:
    infilename = "example.mesh.yaml"
    outfilename = "example.mesh"
input_file = open(infilename, "r")
output_file = open(outfilename, "wb")

yaml_data = input_file.read()
data = yaml.load(yaml_data)

m = Mesh()

# what attribs do we need?
position_attrib = m.vertexattribs.add()
position_attrib.data_type.type = DataType.TYPE_FLOAT # floating point value
position_attrib.data_type.repeats = 3 # 3D
position_attrib.data_type.bytes_per_repeat = 4 # single-precision float
position_attrib.attrib_type = Mesh.VertexAttrib.ATTRIBTYPE_FLOAT
position_attrib.data = "";
position_attrib.name = "VertexPosition";

for vertex in data['vertices']:
    # Pack position
    if "position" in vertex:
        pos = vertex["position"]
        position_attrib.data += struct.pack("<3f", pos[0], pos[1], pos[2])

m.num_vertices = len(data['vertices'])

for triangle in data["triangles"]:
    tri = m.triangles.add()
    tri.vert1 = triangle[0]
    tri.vert2 = triangle[1]
    tri.vert3 = triangle[2]

output_file.write(m.SerializeToString())
output_file.close()
