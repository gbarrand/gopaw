@ECHO off
SETLOCAL

REM # Copyright (C) 2018, Guy Barrand. All rights reserved.
REM # See the file gopaw.license for terms.

REM #////////////////////////////////////////////////////////
REM #// Used by gopaw to produce dll for FORTRAN function. //
REM #////////////////////////////////////////////////////////

REM # Check that FORTRAN is available :
F77.exe 1> NUL 2> NUL
IF ERRORLEVEL 1 (
  ECHO F77.exe program not found. You have to setup FORTRAN environment.
  GOTO obuild_return
)

REM # Check that VisualC++ environment is available :
CL.exe 1> NUL 2> NUL
IF ERRORLEVEL 1 (
  ECHO CL.exe program not found. You have to setup VisualC++ environment.
  GOTO obuild_return
)

REM # To find include files :
IF NOT DEFINED INLIBROOT (
  ECHO Environment variable INLIBROOT not defined.
  GOTO obuild_return
)

SET bin=
SET FILE_NAME=%1%
SET SUFFIX=%2%
SET WRAP_NAME=%3%

REM ECHO %FILE_NAME%
REM ECHO %WRAP_NAME%

IF NOT EXIST %FILE_NAME%.%SUFFIX% (
  ECHO File %FILE_NAME%.%SUFFIX% not found.
  GOTO obuild_return
)
IF NOT EXIST %WRAP_NAME%.cpp (
  ECHO File %WRAP_NAME%.cpp not found.
  GOTO obuild_return
)

IF EXIST %bin%%FILE_NAME%.obj DEL %bin%%FILE_NAME%.obj
IF EXIST %bin%%WRAP_NAME%.obj DEL %bin%%WRAP_NAME%.obj

IF EXIST %bin%%FILE_NAME%.lib DEL %bin%%FILE_NAME%.lib
IF EXIST %bin%%FILE_NAME%.dll DEL %bin%%FILE_NAME%.dll
IF EXIST %bin%%FILE_NAME%.exp DEL %bin%%FILE_NAME%.exp

F77.exe /nologo /MD /compile /obj:%bin%%FILE_NAME%.obj %FILE_NAME%.%SUFFIX% 1> f77_exe_error
IF ERRORLEVEL 1 TYPE f77_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL f77_exe_error 

SET flags=/nologo /MD /O2 /W3 /EHsc /GR 
CL.exe  %flags% /c /DWIN32 /I"%INLIBROOT%" /Fo%bin%%WRAP_NAME%.obj /Tp%WRAP_NAME%.cpp 1> cl_exe_error
IF ERRORLEVEL 1 TYPE cl_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL cl_exe_error 

LINK.exe /nologo /OPT:NOREF /dll /out:%bin%%FILE_NAME%.dll %bin%%WRAP_NAME%.obj %bin%%FILE_NAME%.obj 1> link_exe_error
IF ERRORLEVEL 1 TYPE link_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL link_exe_error 

IF EXIST %bin%%FILE_NAME%.obj DEL %bin%%FILE_NAME%.obj
IF EXIST %bin%%WRAP_NAME%.obj DEL %bin%%WRAP_NAME%.obj

IF EXIST %bin%%FILE_NAME%.exp DEL %bin%%FILE_NAME%.exp

:obuild_return

ENDLOCAL
@ECHO on
