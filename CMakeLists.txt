cmake_minimum_required(VERSION 3.16)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
execute_process(
    COMMAND ${CMAKE_COMMAND} -E create_symlink
        ${CMAKE_BINARY_DIR}/compile_commands.json
        ${CMAKE_SOURCE_DIR}/compile_commands.json
)
project(PlanetarySim LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STARDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_library(glad STATIC vendor/glad/src/glad.cpp)
target_include_directories(glad PUBLIC vendor/glad/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

find_package(OpenGL REQUIRED)

find_package(glm QUIET)

add_executable(PlanetarySim src/main.cpp)

target_link_libraries(PlanetarySim PRIVATE
	glad
	${GLFW_LIBRARIES}
	OpenGL::GL
	dl
)

target_include_directories(PlanetarySim PRIVATE
	${GLFW_INCLUDE_DIRS}
	$<$<BOOL:$GLM_FOUND>:${GLM_INCLUDE_DIRS}>
)

target_compile_options(PlanetarySim PRIVATE ${GLFW_CFLAGS_OTHER})
