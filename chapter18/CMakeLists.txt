cmake_minimum_required(VERSION 3.20)

add_executable(sort)
target_sources(sort PRIVATE sort.cc)
target_compile_features(sort PRIVATE cxx_std_23)

add_executable(plus)
target_sources(plus PRIVATE plus.cc)
target_compile_features(plus PRIVATE cxx_std_23)

add_executable(plusaccumulate)
target_sources(plusaccumulate PRIVATE plusaccumulate.cc)
target_compile_features(plusaccumulate PRIVATE cxx_std_23)

add_executable(strcasecmp)
target_sources(strcasecmp PRIVATE strcasecmp.cc)
target_compile_features(strcasecmp PRIVATE cxx_std_23)

add_executable(classtypeplus)
target_sources(classtypeplus PRIVATE classtypeplus.cc)
target_compile_features(classtypeplus PRIVATE cxx_std_23)

install(TARGETS sort plus plusaccumulate strcasecmp classtypeplus
DESTINATION chapter18)

#install(FILES nstrings.cc DESTINATION chapter13)
