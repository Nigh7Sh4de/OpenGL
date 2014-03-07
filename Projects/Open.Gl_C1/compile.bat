::Some house cleaning:
@ECHO off
set projectName=C1

::Try compiling
g++ -c src\main.cpp -o obj\main.o

::Check if compiler failed
IF %errorlevel%==0 (

	::Try compiling
	g++ -o bin\%projectName%.exe obj\main.o -Llib && (
		
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