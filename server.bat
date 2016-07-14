@echo off
if not exist build (
	mkdir build
)
cd build
::cmake .. -D__GAMEEXE__=server -G"Visual Studio 14 Win64"
::pause
cmake .. -D__GAMEEXE__=server -G"NMake Makefiles"
nmake
nmake install
cd ..
