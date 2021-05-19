cmake_minimum_required(VERSION 3.17)
project(Lu_decomposition_and_the_Gaussian_method)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Lu_decomposition_and_the_Gaussian_method
        MatrixGenerator.cpp
        MatrixGenerator.h
        ProfileMatrix.cpp
        ProfileMatrix.h
        Gaussian.cpp
        Gaussian.h
        luDecomposition.cpp
        luDecomposition.h
        main.cpp
        MatrixOperation.cpp
        MatrixOperation.h)
