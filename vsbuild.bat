:Copyright (c) 2012, 浙江华睿科技有限公司
: All rights reserved

@echo off
set BIN_DIR=Bin
set SOLUTION_FILE=project.sln
set BUILD_LOG=%BIN_DIR%\build.log
set RES_DIR="Resource"
set BUILD_DIR=Build
set USE_DOC=1

@if exist %BIN_DIR% @rd /q /s %BIN_DIR%

set p=%~dp0
for /f "delims=" %%i in ("%p:~0,-1%") do (set PRJ_NAME=%%~ni)
set EXP_DIR=Export\%PRJ_NAME%
rem create dir
@if exist %EXP_DIR% rd /s /q %EXP_DIR%
@mkdir %EXP_DIR%\bin
@mkdir %EXP_DIR%\lib
@mkdir %EXP_DIR%\include

rem clean the work environment

if exist %BUILD_LOG% del %BUILD_LOG%

rem svn file
if exist svn @svn checkout http://10.35.2.21/svn/MachineVision/Include/Utils/AlgInternal %RES_DIR%\AlgInternal
if exist svn @svn checkout http://10.35.2.21/svn/MachineVision/MachineVision/Identification/DataCode/Trunk/opencv %RES_DIR%\opencv 

rem Setting environment for using Microsoft Visual Studio 2013 x86 tools.
call "%VS120COMNTOOLS%vsvars32.bat"

rem ================================================================
echo Build %PRJ_NAME% Release ...
devenv %SOLUTION_FILE% /Rebuild Release /Out %BUILD_LOG%
echo Build %PRJ_NAME% Debug ...
devenv %SOLUTION_FILE% /Rebuild Debug /Out %BUILD_LOG%

echo Build over.
rem ================================================================

rem View build result
echo View the build log of %BUILD_LOG%.
rem ================================================================

rem package the bin code
@for /r %BIN_DIR% %%i in (*.dll *.exe) do copy /y %%i %EXP_DIR%\bin
@for /r %BIN_DIR% %%i in (*.lib) do copy /y %%i %EXP_DIR%\lib
@xcopy /y Include %EXP_DIR%\include

rem clean the work
@if exist %BIN_DIR% rd /s /q %BIN_DIR%
@for /r %BUILD_DIR% %%i in (Debug,debug,Release,release) do (if exist %%i @rd /q /s %%i)
@for /r %BUILD_DIR% %%i in (*.sdf *.opensdf) do @del /s /q /f %%i

echo 从 %EXP_DIR% 文件夹中获取最新的库
pause
