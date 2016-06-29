@echo off
if not exist build (
	mkdir build
)
cd build
cmake .. -G"Visual Studio 14 Win64"
pause
devenv engine.sln /build
pause
