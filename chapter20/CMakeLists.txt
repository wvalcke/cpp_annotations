cmake_minimum_required(VERSION 3.20)

add_executable(hello)
target_sources(hello PRIVATE hello.cc)
target_compile_features(hello PRIVATE cxx_std_23)

add_executable(threadargs)
target_sources(threadargs PRIVATE threadargs.cc)
target_compile_features(threadargs PRIVATE cxx_std_23)

install(TARGETS hello threadargs
DESTINATION chapter20)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
