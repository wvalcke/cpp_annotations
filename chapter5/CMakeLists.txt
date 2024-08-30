cmake_minimum_required(VERSION 3.20)

add_executable(stringliteral)
target_sources(stringliteral PRIVATE stringliteral.cpp)
target_compile_features(stringliteral PRIVATE cxx_std_23)

add_executable(stringview)
target_sources(stringview PRIVATE stringview.cpp)
target_compile_features(stringview PRIVATE cxx_std_23)

install(TARGETS stringliteral stringview DESTINATION chapter5)
