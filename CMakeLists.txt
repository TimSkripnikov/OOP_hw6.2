cmake_minimum_required(VERSION 3.10)

project(TimeProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    Time.cpp
)

set(HEADERS
    Time.hpp
)

add_executable(main ${SOURCES} ${HEADERS})
