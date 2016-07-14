@echo off
if not exist build (
	mkdir build
)
cd build
::cmake .. -D__GAMEEXE__=client -G"Visual Studio 14 Win64"
::pause
cmake .. -D__GAMEEXE__=client -G"NMake Makefiles"
nmake
nmake install
cd ..
