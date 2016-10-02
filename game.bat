@echo off
if not exist game (
	mkdir game
)
cd game
cmake .. -D__GAMEEXE__=game -G"NMake Makefiles"
nmake
nmake install
cd ..
