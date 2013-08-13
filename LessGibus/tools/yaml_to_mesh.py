from protobuf import Mesh

import yaml, sys

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

for vertex in data["vertices"]:
    v = m.vertices.add()
    if "position" in vertex:
        v.position.x = vertex['position'][0]
        v.position.y = vertex['position'][1]
        v.position.z = vertex['position'][2]

for triangle in data["triangles"]:
    tri = m.triangles.add()
    tri.vert1 = triangle[0]
    tri.vert2 = triangle[1]
    tri.vert3 = triangle[2]

output_file.write(m.SerializeToString())
output_file.close()
