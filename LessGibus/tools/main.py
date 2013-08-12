from protobuf import Mesh

m = Mesh()
m.material_path = "material/trivial"

for i in [(-1, 0, 0), (1, 0, 0), (0, 1, 0)]:
    v = m.vertices.add()
    v.position.x = i[0]
    v.position.y = i[1]
    v.position.z = i[2]

for i in [(0, 1, 2)]:
    t = m.triangles.add()
    t.vert1 = i[0]
    t.vert2 = i[1]
    t.vert3 = i[2]
