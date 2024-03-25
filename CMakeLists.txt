cmake_minimum_required(VERSION 2.8)

project(Assignment1)


add_executable(amesWindow.out amesWindow.cpp)
add_executable(userInteraction.out userInteraction.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries( amesWindow.out ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
target_link_libraries( userInteraction.out ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )
