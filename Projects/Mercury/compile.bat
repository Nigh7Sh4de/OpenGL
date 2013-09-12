@echo on

cd "C:\Users\Dennis\Github\OpenGL\Projects\Mercury\src"
dir

g++ -c Mercury.cpp

::Remember to change location of libs to Project folder for ease of use
g++ -o ../Mercury.exe Mercury.o -lglfw3 -lglew32 -lgdi32 -lopengl32


cd ..
Mercury.exe

::PAUSE