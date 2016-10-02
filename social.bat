@echo off
if not exist social (
	mkdir social
)
cd social
cmake .. -D__GAMEEXE__=social -G"NMake Makefiles"
nmake
nmake install
cd ..
