$BuildOut = 'builds'
if (!(Test-Path -Path $BuildOut)) {
    New-Item -ItemType Directory -Force -Path $BuildOut
}

Push-Location -Path $BuildOut
Write-Host "current directory $BuildOut"

cmake .. -G "Visual Studio 16 2019" -A x64 -DCMAKE_TOOLCHAIN_FILE="$PSScriptRoot/vcpkg/scripts/buildsystems/vcpkg.cmake" -DVCPKG_TARGET_TRIPLET=x64-windows-static
cmake --build .

if ($LastExitCode -eq 0) {
    Write-Host "start running..."
    Write-Host "#############################################################################"

    ./Debug/TemplateProject.exe
}

Pop-Location
