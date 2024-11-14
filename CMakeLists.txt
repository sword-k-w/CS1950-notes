cmake_minimum_required(VERSION 3.22)
project(StreamCipher)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(StreamCipher
        Salsa-decryption.cpp
        Salsa20-encryption.cpp
    simulator.cpp
        Alice.cpp
        Bob.cpp)
