@echo off

echo ----------Input File----------

set /p input=
echo %input%.exe

echo ----------Compling----------
g++ -finput-charset=utf-8 -fexec-charset=gbk %input%.cpp -o %input%.exe^
    -L. -lgl_wrapper -lglfw_wrapper 

echo ----------Running----------
%input%.exe

echo ----------End----------
pause
