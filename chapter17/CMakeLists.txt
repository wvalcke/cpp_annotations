cmake_minimum_required(VERSION 3.20)

add_executable(accessouter)
target_sources(accessouter PRIVATE accessouter.cpp)
target_compile_features(accessouter PRIVATE cxx_std_23)

add_executable(surround2)
target_sources(surround2 PRIVATE surround2.cpp)
target_compile_features(surround2 PRIVATE cxx_std_23)

add_executable(surround3)
target_sources(surround3 PRIVATE surround3.cpp)
target_compile_features(surround3 PRIVATE cxx_std_23)

add_executable(emptyenum)
target_sources(emptyenum PRIVATE emptyenum.cpp)
target_compile_features(emptyenum PRIVATE cxx_std_23)

add_executable(virtconstruct)
target_sources(virtconstruct PRIVATE virtconstruct.cpp)
target_compile_features(virtconstruct PRIVATE cxx_std_23)

install(TARGETS accessouter surround2 surround3 emptyenum virtconstruct
DESTINATION chapter17)

#install(FILES nstrings.cc DESTINATION chapter13)
