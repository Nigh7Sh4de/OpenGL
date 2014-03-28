::Some house cleaning:
@ECHO off
set projectName=HelloWorld

::Try compiling
g++ -c src\main.cpp -o obj\main.o -Iinclude

::Check if compiler failed
IF %errorlevel%==0 (

	::Try compiling
	g++ -o bin\%projectName%.exe obj\main.o -Llib -lsfml-window-s -lsfml-system-s && (
		
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