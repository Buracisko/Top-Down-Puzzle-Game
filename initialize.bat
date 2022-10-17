@echo off
if "%~1"=="" goto fail
set target=%~1

echo Target folder is: "%target%"
if not exist "%target%" mkdir "%target%"
cmake -S . -B "%target%"

if not exist "%target%/assets" (
	mklink /j "%target%/assets" "./assets"
)

exit

:fail
@echo Please, specify build folder
