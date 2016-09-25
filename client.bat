@echo off
if not exist client (
	mkdir client
)
cd client
cmake .. -D__GAMEEXE__=client -G"NMake Makefiles"
nmake
nmake install
cd ..
