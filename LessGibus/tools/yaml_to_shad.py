from protobuf import ShaderProgram

import yaml, sys

if (len(sys.argv) >= 3):
    infilename = sys.argv[1]
    outfilename = sys.argv[2]
else:
    infilename = "example.shad.yaml"
    outfilename = "example.shad"
input_file = open(infilename, "r")
output_file = open(outfilename, "wb")

yaml_data = input_file.read()
data = yaml.load(yaml_data)

prog = ShaderProgram()

for shader in data['shaders']:
    s = prog.shaders.add()

    s.filename = shader['filename']
    
    if (shader['type'] == "compute"):
        s.type = ShaderProgram.COMPUTE_SHADER
    elif (shader['type'] == "vertex"):
        s.type = ShaderProgram.VERTEX_SHADER
    elif (shader['type'] == "tess_control"):
        s.type = ShaderProgram.TESS_CONTROL_SHADER
    elif (shader['type'] == "tess_evaluation"):
        s.type = ShaderProgram.TESS_EVALUATION_SHADER
    elif (shader['type'] == "geometry"):
        s.type = ShaderProgram.GEOMETRY_SHADER
    elif (shader['type'] == "fragment"):
        s.type = ShaderProgram.FRAGMENT_SHADER

output_file.write(prog.SerializeToString())
output_file.close()
