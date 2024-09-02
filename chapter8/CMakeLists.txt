cmake_minimum_required(VERSION 3.20)

add_executable(constexpr)
target_sources(constexpr PRIVATE constexpr.cpp)
target_compile_features(constexpr PRIVATE cxx_std_23)

add_executable(constexpr2)
target_sources(constexpr2 PRIVATE constexpr2.cpp)
target_compile_features(constexpr2 PRIVATE cxx_std_23)

add_executable(staticmemberfunction)
target_sources(staticmemberfunction PRIVATE staticmemberfunction.cpp)
target_compile_features(staticmemberfunction PRIVATE cxx_std_23)

install(TARGETS constexpr constexpr2 staticmemberfunction
DESTINATION chapter8)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter7)
