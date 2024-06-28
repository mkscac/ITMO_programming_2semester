cmake_minimum_required(VERSION 3.26)
project(prg_laba8_cubeRubiks)

set(CMAKE_CXX_STANDARD 23)

set(OpenGL_GL_PREFERENCE GLVND)
add_executable(prg_laba8_cubeRubiks
        main.cpp
        structures.h
        cube.h
        cube_fun.cpp
        main_functions.h
        main_functions_realiz.cpp
        menu.h
        menu_fun.cpp

)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(prg_laba8_cubeRubiks ${OPENGL_LIBRARIES} ${GLUT_LIBRARY})

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
target_link_libraries(prg_laba8_cubeRubiks glfw GLEW::GLEW)

#Это сообщит линковщику, что нужно использовать фреймворк GLUT при сборке вашего проекта
target_link_libraries(prg_laba8_cubeRubiks ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} "-framework GLUT")