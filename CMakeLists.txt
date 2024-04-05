cmake_minimum_required(VERSION 3.27)
project(ImageProcessv2)

set(CMAKE_CXX_STANDARD 17)

add_executable(ImageProcessv2 main.cpp
        Image.cpp
        Point.cpp
        Rect.cpp
        Size.cpp
        ImageProcessing.cpp
        ImageProcessing.h)
