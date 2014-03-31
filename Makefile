
all: MokituSolver

MokituSolver:
	@echo 'Compilation...'
	g++ -O3 -std=c++0x -o"MokituSolver" `ls ./src/*/*.cpp` -lgecodeflatzinc -lgecodedriver -lgecodesearch -lgecodeminimodel -lgecodeset -lgecodeint -lgecodefloat -lgecodekernel -lgecodesupport `wx-config --cppflags --libs`
