cmake_minimum_required(VERSION 3.10)
project(daysproject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  # ← ДОБАВЬТЕ ЭТУ СТРОЧКУ

add_executable(daysproject
    main.cpp
    release.cpp
)