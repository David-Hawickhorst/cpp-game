# basic cmake stuff
cmake_minimum_required(VERSION 3.10)
project(cpp-game)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add some compiler options
add_compile_options(--std=c++17 -g -Wall -Wextra -Wshadow -Wconversion -pedantic)


# create a target that is an executable called "sfml_examples" and "main.cpp" (and potentially other files)
# will be what are compiled into the executable
add_executable(${PROJECT_NAME} main.cpp
               Components.h
               Vec2.h
               Vec2.cpp
               Entity.cpp
               Entity.h
               EntityManager.cpp
               EntityManager.h
               Game.cpp
               Game.h
               Systems.h
               Configurations.h
)

# this is how to locate the 3rd party package from your system
find_package(SFML COMPONENTS graphics window system REQUIRED)

# this does the linking of the libraries
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
