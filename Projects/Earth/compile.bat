::Some house cleaning:
@ECHO off

set projectName=Earth

::Try compiling
g++ -c src\%projectName%.cpp -o obj\%projectName%.o -std=gnu++0x

::Move dynamic libraries
REM xcopy lib\glew32.dll bin /Y

::Check if compiler failed
IF %errorlevel%==0 (

	::Try linking
	g++ -o bin\%projectName%.exe obj\%projectName%.o -Llib -lSOIL -lglew32s -lgdi32 -lopengl32 -lglfw3 -v && (
		
		::If linked successfully
		ECHO Successfull! && ECHO Running: && ECHO.
		bin\%projectName%.exe

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