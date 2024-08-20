cmake_minimum_required(VERSION 3.18)

add_executable(koenig)
target_sources(koenig PRIVATE koenig.cpp)
target_compile_features(koenig PRIVATE cxx_std_20)

