cmake_minimum_required(VERSION 3.0)

project(raytracer VERSION 0.1 LANGUAGES CXX)

include_directories(${raytracer_SOURCE_DIR}/include)

file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(raytracer ${SOURCES})
target_compile_features(raytracer PRIVATE cxx_std_17)
