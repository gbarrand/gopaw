@ECHO off
SETLOCAL

REM # Copyright (C) 2018, Guy Barrand. All rights reserved.
REM # See the file gopaw.license for terms.

REM #//////////////////////////////////////////////////////////
REM #// Used by Lib to produce dll for C function.           //
REM #//////////////////////////////////////////////////////////

REM # Check that VisualC++ environment is available :
CL.exe 1> NUL 2> NUL
IF ERRORLEVEL 1 (
  ECHO CL.exe program not found. You have to setup VisualC++ environment.
  GOTO obuild_return
)

REM # Visual Studio >= 9.0 :
IF NOT DEFINED VCINSTALLDIR (
  ECHO Environment variable VCINSTALLDIR not defined.
  GOTO obuild_return
)

REM # To find include files :
IF NOT DEFINED INLIBROOT (
  ECHO Environment variable INLIBROOT not defined.
  GOTO obuild_return
)
IF NOT DEFINED GOPAWROOT (
  ECHO Environment variable GOPAWROOT not defined.
  GOTO obuild_return
)

SET bin=
SET FILE_NAME=%1%
SET SUFFIX=%2%
SET WRAP_NAME=%3%

REM ECHO %FILE_NAME%
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

SET flags=/nologo /MD /O2 /W3
SET src=%FILE_NAME%.%SUFFIX%
IF "%SUFFIX%" NEQ "c" (
  SET flags=/nologo /MD /O2 /W3 /EHsc /GR
  SET src=/Tp%FILE_NAME%.%SUFFIX%
)

CL.exe %flags% /c /I"%INLIBROOT%" /I"%GOPAWROOT%" /I"%GOPAWROOT%\HBOOK" /Fo%bin%%FILE_NAME%.obj %src% 1> cl_exe_error
IF ERRORLEVEL 1 TYPE cl_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL cl_exe_error 

SET flags=/nologo /MD /O2 /W3 /EHsc /GR
CL.exe %flags% /c /I"%INLIBROOT%" /Fo%bin%%WRAP_NAME%.obj /Tp%WRAP_NAME%.cpp 1> cl_exe_error
IF ERRORLEVEL 1 TYPE cl_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL cl_exe_error 

SET plugin_linker="%VCINSTALLDIR%"\bin\LINK.exe

%plugin_linker% /nologo /dll /out:%bin%%FILE_NAME%.dll %bin%%WRAP_NAME%.obj %bin%%FILE_NAME%.obj 1> link_exe_error
IF ERRORLEVEL 1 TYPE link_exe_error && GOTO obuild_return
IF NOT ERRORLEVEL 1 DEL link_exe_error 

IF EXIST %bin%%FILE_NAME%.obj DEL %bin%%FILE_NAME%.obj
IF EXIST %bin%%WRAP_NAME%.obj DEL %bin%%WRAP_NAME%.obj

IF EXIST %bin%%FILE_NAME%.exp DEL %bin%%FILE_NAME%.exp

:obuild_return

ENDLOCAL
@ECHO on
