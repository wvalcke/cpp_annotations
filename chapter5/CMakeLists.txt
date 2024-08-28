cmake_minimum_required(VERSION 3.20)

add_executable(stringliteral)
target_sources(stringliteral PRIVATE stringliteral.cpp)
target_compile_features(stringliteral PRIVATE cxx_std_23)
