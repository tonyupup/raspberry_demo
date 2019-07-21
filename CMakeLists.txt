project(main)
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)


SET(ARM_ROOT "/mnt/utils/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64")
SET(CMAKE_C_COMPILER "${ARM_ROOT}/bin/arm-linux-gnueabihf-gcc")
SET(CMAKE_C_FLAGS  "${CMAKE_C_FLAGS} -std=c99")
include_directories("/home/enh/src/source/cross_build_root/include")
LINK_DIRECTORIES("/home/enh/src/source/cross_build_root/lib")


AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_LIBRARY(distance STATIC distance.c)
ADD_EXECUTABLE(main ${DIR_SRCS})
target_link_libraries(main wiringPi)
target_link_libraries(main distance)