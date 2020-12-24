cmake_minimum_required(VERSION 3.17)
project(CollectionLibrary)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(CollectionLibrary main.cpp
		src/collectable.cpp
        src/lista.cpp
        src/coda.cpp
        src/stack.cpp
		src/set.cpp
		)

add_subdirectory(tests)