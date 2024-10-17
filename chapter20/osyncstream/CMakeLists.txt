cmake_minimum_required(VERSION 3.20)

add_executable(osyncstream)
target_sources(osyncstream PRIVATE main.cc)
target_compile_features(osyncstream PRIVATE cxx_std_23)

install(TARGETS osyncstream
DESTINATION chapter20)
