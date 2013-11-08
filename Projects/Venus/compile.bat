::Some house cleaning:
@ECHO off

set projectName=Venus

CD "C:\Users\Dennis\Github\OpenGL\Projects\%projectName%"

::Try compiling
g++ -c src\%projectName%.cpp -o obj\%projectName%.o

::Check if compiler failed
IF %errorlevel%==0 (

	::Try compiling
	g++ -o bin\%projectName%.exe obj\%projectName%.o -Llib -lglfw3 -lglew32 -lgdi32 -lopengl32 && (
		
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