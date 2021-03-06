::Some house cleaning:
@ECHO off
set projectName=Mercury

::Try compiling
g++ -c src\%projectName%.cpp -o obj\%projectName%.o -Iinclude

::Check if compiler failed
IF %errorlevel%==0 (

	::Try compiling
	g++ -o bin\%projectName%.exe obj\%projectName%.o -Llib -lglfw3 -lopengl32 && (
		
		::If linked successfully
		ECHO Successfull! && ECHO Running: && ECHO.
		bin\%projectName%.exe

	) || (
	
		::If link failed
		ECHO.
		ECHO -----------------------
		ECHO --Linker Done Goffed!--
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