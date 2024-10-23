cmake_minimum_required(VERSION 3.20)

add_executable(iterators)
target_sources(iterators PRIVATE iterators.cc)
target_compile_features(iterators PRIVATE cxx_std_23)

add_library(reviter STATIC)
target_sources(reviter PRIVATE reverseiterators.cc)
target_compile_features(reviter PRIVATE cxx_std_23)

install(TARGETS iterators reviter
DESTINATION chapter22)
