cmake_minimum_required(VERSION 3.20)

add_executable(derived)
target_sources(derived PRIVATE derived.cpp)
target_compile_features(derived PRIVATE cxx_std_23)

install(TARGETS derived
DESTINATION chapter13)
