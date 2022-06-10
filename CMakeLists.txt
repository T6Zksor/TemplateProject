################################################################################

cmake_minimum_required(VERSION 3.15)

project(
    TemplateProject
    VERSION 1.0
    LANGUAGES CXX)

set(sources
    src/main.cc
)

add_executable(${PROJECT_NAME} ${sources})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

################################################################################
