@echo off
if not exist agent (
	mkdir agent
)
cd agent
cmake .. -D__GAMEEXE__=agent -G"NMake Makefiles"
nmake
nmake install
cd ..
