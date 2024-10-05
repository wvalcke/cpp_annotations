cmake_minimum_required(VERSION 3.20)

add_executable(initializing)
target_sources(initializing PRIVATE initializing.cc)
target_compile_features(initializing PRIVATE cxx_std_23)

add_executable(using)
target_sources(using PRIVATE using.cc)
target_compile_features(using PRIVATE cxx_std_23)

add_executable(union)
target_sources(union PRIVATE union.cc)
target_compile_features(union PRIVATE cxx_std_23)

add_executable(size)
target_sources(size PRIVATE size.cc)
target_compile_features(size PRIVATE cxx_std_23)

add_executable(pointersize)
target_sources(pointersize PRIVATE pointersize.cc)
target_compile_features(pointersize PRIVATE cxx_std_23)

install(TARGETS initializing using union size pointersize
DESTINATION chapter16)

#install(FILES nstrings.cc DESTINATION chapter13)
