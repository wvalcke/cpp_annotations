cmake_minimum_required(VERSION 3.20)

add_executable(koenig)
target_sources(koenig PRIVATE koenig.cpp)
target_compile_features(koenig PRIVATE cxx_std_23)

add_executable(koenig2)
target_sources(koenig2 PRIVATE koenig2.cpp)
target_compile_features(koenig2 PRIVATE cxx_std_23)
