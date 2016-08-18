@echo off
if not exist client (
	mkdir client
)
cd client
::cmake .. -D__GAMEEXE__=client -G"Visual Studio 14 Win64"
::pause
cmake .. -D__GAMEEXE__=agent -G"NMake Makefiles"
nmake
nmake install
cd ..
