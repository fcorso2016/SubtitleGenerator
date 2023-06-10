cmake_minimum_required(VERSION 3.15)

set(CMAKE_PROJECT_TOP_LEVEL_INCLUDES ${CMAKE_SOURCE_DIR}/cmake/conan_provider.cmake)
project(SubtitleGenerator CXX) # if the project uses c++

set(CMAKE_CXX_STANDARD 20)

find_package(ffmpeg REQUIRED CONFIG)
find_package(Qt5 REQUIRED CONFIG COMPONENTS Core Gui Widgets)
find_package(whisper-cpp REQUIRED CONFIG)

add_subdirectory(FileConverter)

set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/Install)
install(FILES ${ffmpeg_INCLUDE_DIR}/../bin/ffmpeg.exe DESTINATION ${CMAKE_INSTALL_PREFIX})