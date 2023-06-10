project(FileConverter)

set(${PROJECT_NAME}_SOURCES WavConverter.cpp)

add_library(${PROJECT_NAME} STATIC ${${PROJECT_NAME}_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC Qt5::Core)