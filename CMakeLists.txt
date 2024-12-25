cmake_minimum_required(VERSION 3.29)
project(doctors)

set(CMAKE_CXX_STANDARD 20)

add_executable(doctors main.cpp
        patient.cpp
        patient.h
        doctors.cpp
        doctors.h
        hospital.cpp
        hospital.h)
