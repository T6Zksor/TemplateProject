$BuildOut = 'builds'
if (!(Test-Path -Path $BuildOut)) {
    New-Item -ItemType Directory -Force -Path $BuildOut
}

Push-Location -Path $BuildOut
Write-Host "current directory $BuildOut"

#-DVCPKG_TARGET_TRIPLET=x64-windows-static
#-DCMAKE_PREFIX_PATH="path/to/Qt5/lib/cmake"
cmake .. -G "Visual Studio 16 2019" -A x64 -DCMAKE_PREFIX_PATH="D:\\Qt\\5.15.2\\msvc2019_64\\lib\\cmake" -DCMAKE_TOOLCHAIN_FILE="$PSScriptRoot/vcpkg/scripts/buildsystems/vcpkg.cmake"
cmake --build .

if ($LastExitCode -eq 0) {
    Write-Host "start running..."
    Write-Host "#############################################################################"

    #./src/Debug/main.exe
}

Pop-Location
