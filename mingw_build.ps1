if(Test-Path -Path mingw_build){}else{
    mkdir mingw_build
}
cd mingw_build
cmake -G"MinGW Makefiles" ..
cmake --build . --config Release
cd ..
cp mingw_build/ktm.exe "ktm-mingw_build.exe"
./"ktm-mingw_build.exe"
