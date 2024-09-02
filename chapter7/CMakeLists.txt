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

add_executable(ambiguity)
target_sources(ambiguity PRIVATE ambiguity.cpp)
target_compile_features(ambiguity PRIVATE cxx_std_23)

add_executable(ambiguity2)
target_sources(ambiguity2 PRIVATE ambiguity2.cpp)
target_compile_features(ambiguity2 PRIVATE cxx_std_23)

add_executable(uniforminit)
target_sources(uniforminit PRIVATE uniforminit.cpp)
target_compile_features(uniforminit PRIVATE cxx_std_23)

add_executable(constobj)
target_sources(constobj PRIVATE constobj.cpp)
target_compile_features(constobj PRIVATE cxx_std_23)

add_executable(localclass)
target_sources(localclass PRIVATE localclass.cpp)
target_compile_features(localclass PRIVATE cxx_std_23)

install(TARGETS demo personmain constructorder ambiguity ambiguity2 uniforminit
    constobj localclass
DESTINATION chapter7)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter7)
