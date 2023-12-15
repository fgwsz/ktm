if(Test-Path -Path msvc_build){}else{
    mkdir msvc_build
}
cd msvc_build
cmake -G"Visual Studio 17 2022" ..
cmake --build . --config Release
cd ..
cp msvc_build/Release/ktm.exe ktm.exe
./ktm.exe
