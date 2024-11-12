cmake_minimum_required(VERSION 3.22)
project(StreamCipher)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(StreamCipher
        OTP-decryption.cpp
        OTP-encryption.cpp
    simulator.cpp
        Alice.cpp
        Bob.cpp)
