cmake_minimum_required(VERSION 3.20)

add_executable(intarray)
target_sources(intarray PRIVATE intarray.cc mainintarray.cc)
target_compile_features(intarray PRIVATE cxx_std_23)

add_executable(multiindex)
target_sources(multiindex PRIVATE multiindex.cc)
target_compile_features(multiindex PRIVATE cxx_std_23)


install(TARGETS intarray multiindex
DESTINATION chapter11)
