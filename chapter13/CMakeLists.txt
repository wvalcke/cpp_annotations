cmake_minimum_required(VERSION 3.20)

add_executable(derived)
target_sources(derived PRIVATE derived.cpp)
target_compile_features(derived PRIVATE cxx_std_23)

add_executable(inheretconstruct)
target_sources(inheretconstruct PRIVATE inheretconstruct.cpp)
target_compile_features(inheretconstruct PRIVATE cxx_std_23)

add_executable(aggregateinit)
target_sources(aggregateinit PRIVATE aggregateinit.cpp)
target_compile_features(aggregateinit PRIVATE cxx_std_23)

add_executable(destructbase)
target_sources(destructbase PRIVATE destructbase.cpp)
target_compile_features(destructbase PRIVATE cxx_std_23)

add_executable(nstrings)
target_sources(nstrings PRIVATE nstrings.cc)
target_compile_features(nstrings PRIVATE cxx_std_23)

add_executable(initplacenew)
target_sources(initplacenew PRIVATE initplacenew.cc)
target_compile_features(initplacenew PRIVATE cxx_std_23)

install(TARGETS derived inheretconstruct aggregateinit destructbase nstrings
    initplacenew
DESTINATION chapter13)

install(FILES nstrings.cc DESTINATION chapter13)
