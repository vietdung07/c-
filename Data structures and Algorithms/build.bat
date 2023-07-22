@echo off

rem Set the compiler and compiler flags
set CXX=g++
set CXXFLAGS=-std=c++17

rem Compile all .cpp files into .o files
for %%i in (*.cpp) do (
    %CXX% %CXXFLAGS% -c "%%i" -o "%%~ni.o"
)
setlocal enabledelayedexpansion
rem Link all .o files into a single executable
set "OBJECTS="
for %%i in (*.o) do (
    set OBJECTS=!OBJECTS! "%%i"
)
%CXX% %CXXFLAGS% %OBJECTS% -o program

rem Clean up the .o files
del *.o

rem Run the program
.\program
