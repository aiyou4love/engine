@echo off
if not exist client (
	mkdir client
)
cd client
cmake .. -D__GAMEEXE__=agent -G"NMake Makefiles"
nmake
nmake install
cd ..
