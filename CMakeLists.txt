################################################################################

cmake_minimum_required(VERSION 3.15)

cmake_policy(SET CMP0091 NEW)

project(
    TemplateProject
    VERSION 1.0
    LANGUAGES CXX)

set(sources
    src/main.cc
)

add_executable(${PROJECT_NAME} ${sources})

################################################################################

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set_property(TARGET ${PROJECT_NAME} PROPERTY
             MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

################################################################################

find_package(ZLIB REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE ZLIB::ZLIB)

find_package(unofficial-libuv CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE unofficial::libuv::libuv)

################################################################################
