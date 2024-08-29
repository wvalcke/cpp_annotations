cmake_minimum_required(VERSION 3.20)

add_executable(statusflags)
target_sources(statusflags PRIVATE statusflags.cpp)
target_compile_features(statusflags PRIVATE cxx_std_23)

add_executable(align)
target_sources(align PRIVATE align.cpp)
target_compile_features(align PRIVATE cxx_std_23)
