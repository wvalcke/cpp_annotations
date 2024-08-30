cmake_minimum_required(VERSION 3.20)

add_executable(demo)
target_sources(demo PRIVATE demo.cpp)
target_compile_features(demo PRIVATE cxx_std_23)

add_executable(personmain)
target_sources(personmain PRIVATE person.cpp personmain.cpp)
target_compile_features(personmain PRIVATE cxx_std_23)

add_executable(constructorder)
target_sources(constructorder PRIVATE constructorder.cpp)
target_compile_features(constructorder PRIVATE cxx_std_23)

install(TARGETS demo personmain constructorder
DESTINATION chapter7)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter7)
