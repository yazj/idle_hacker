cmake_minimum_required(VERSION 3.28)
project(idle_hacker LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 3.0.2
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL SYSTEM
  FIND_PACKAGE_ARGS 3.0.2 COMPONENTS graphics window system audio)

FetchContent_Declare(
  spdlog
  GIT_REPOSITORY https://github.com/gabime/spdlog.git
  GIT_TAG v1.x
  GIT_SHALLOW ON
  EXCLUDE_FROM_ALL SYSTEM
  FIND_PACKAGE_ARGS 1.10.0
)

FetchContent_MakeAvailable(SFML spdlog)

set(SOURCES
    src/main.cpp
    src/terminal/terminal.cpp
    src/render/render.cpp
    src/buffer/buffer.cpp
    src/input/input_handler.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
target_link_libraries(${PROJECT_NAME} PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PRIVATE 
    "${CMAKE_CURRENT_SOURCE_DIR}/src"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)


set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT
                                                            ${PROJECT_NAME})
