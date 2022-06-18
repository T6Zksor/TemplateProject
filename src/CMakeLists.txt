################################################################################

cmake_minimum_required(VERSION 3.15)

cmake_policy(SET CMP0091 NEW)

################################################################################

set(PROJ_TARGET_NAME main)

# Turn on automatic invocation of the MOC, UIC & RCC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

################################################################################

set(sources
    main.cc
    mainwindow.h
    mainwindow.cc
    mainwindow.ui
    resources.qrc
)

add_executable(${PROJ_TARGET_NAME} ${sources})

################################################################################

target_compile_features(${PROJ_TARGET_NAME} PRIVATE cxx_std_17)

set_property(TARGET ${PROJ_TARGET_NAME} PROPERTY
             MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

################################################################################

find_package(ZLIB REQUIRED)
target_link_libraries(${PROJ_TARGET_NAME} PRIVATE ZLIB::ZLIB)

find_package(unofficial-libuv CONFIG REQUIRED)
target_link_libraries(${PROJ_TARGET_NAME} PRIVATE unofficial::libuv::libuv)

find_package(Qt5 REQUIRED COMPONENTS Widgets)
target_link_libraries(${PROJ_TARGET_NAME} PRIVATE Qt5::Widgets Qt5::Gui Qt5::Core)

################################################################################
