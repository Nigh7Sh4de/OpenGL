@echo on

cd "C:\Users\Dennis\Github\opengl-1\Projects\Mercury\src"
dir

g++ -c Mercury.cpp
g++ -o ../Mercury.exe Mercury.o -lglfw3 -lglew32 -lgdi32 -lopengl32

cd ..
Mercury.exe

PAUSE