cmake_minimum_required(VERSION 3.20)

add_executable(rawbytes)
target_sources(rawbytes PRIVATE rawbytes.cpp)
target_compile_features(rawbytes PRIVATE cxx_std_23)

install(TARGETS rawbytes
DESTINATION chapter9)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter7)
