::Some house cleaning:
@ECHO off

set projectName=Cube

::Try compiling
IF %errorlevel%==0 g++ -c src\%projectName%.cpp -o obj\%projectName%.o -std=gnu++0x -Iinclude -g
IF %errorlevel%==0 g++ -c include\GLSLTools.cpp -o obj\GLSLTools.o -std=gnu++0x -Iinclude -g

::Move dynamic libraries
IF %errorlevel%==0 copy src\FragmentSource.glsl bin\FragmentSource.glsl
IF %errorlevel%==0 copy src\VertexSource.glsl bin\VertexSource.glsl

::Check if compiler failed
IF %errorlevel%==0 (

	::Try linking
	g++ -o bin\%projectName%.exe obj\%projectName%.o obj\GLSLTools.o -Llib -lglfw3 -lglew32s -lgdi32 -lopengl32 -mwindows -g && (
		
		::If linked successfully
		ECHO Successfull! && ECHO Running: && ECHO.
		cd bin
		%projectName%.exe

	) || (
	
		::If link failed
		ECHO.
		ECHO -----------------------
		ECHO --Linker Done Goofed!--
		ECHO -----------------------
		PAUSE
	)
) ELSE (

	::If compiler failed
	ECHO.
	ECHO -------------------------
	ECHO --Compiler Done Goofed!--
	ECHO -------------------------
	PAUSE
)

REM PAUSE