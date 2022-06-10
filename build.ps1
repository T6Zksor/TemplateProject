$BuildOut = 'builds'
if (!(Test-Path -Path $BuildOut)) {
    New-Item -ItemType Directory -Force -Path $BuildOut
}

Push-Location -Path $BuildOut
Write-Host "current directory $BuildOut"

cmake .. -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .

Write-Host "start running..."
Write-Host "#############################################################################"

./Debug/TemplateProject.exe

Pop-Location
