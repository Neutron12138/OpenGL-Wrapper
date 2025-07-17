@echo off

echo ----------Compling----------
g++ -finput-charset=utf-8 -fexec-charset=gbk "../gl_wrapper/dll_main.cpp"^
    -o "gl_wrapper.dll" -shared -DGL_WRAPPER_INCLUDE_GLAD_IMPL

echo ----------End----------
pause
