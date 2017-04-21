call "C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\VCVARSALL.BAT " x86

cd .
nmake -f Project3.mk  EXT_MODE=1 ISPROTECTINGMODEL=NOTPROTECTING
@if errorlevel 1 goto error_exit
exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
An_error_occurred_during_the_call_to_make
