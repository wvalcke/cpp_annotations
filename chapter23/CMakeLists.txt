cmake_minimum_required(VERSION 3.20)

add_executable(basename2)
target_sources(basename2 PRIVATE basename2.cc)
target_compile_features(basename2 PRIVATE cxx_std_23)

install(TARGETS basename2 
DESTINATION chapter23)
