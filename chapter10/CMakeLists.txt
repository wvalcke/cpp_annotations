cmake_minimum_required(VERSION 3.20)

add_executable(exception_ex1)
target_sources(exception_ex1 PRIVATE exception_ex1.cpp)
target_compile_features(exception_ex1 PRIVATE cxx_std_23)

add_executable(exception_ex2)
target_sources(exception_ex2 PRIVATE exception_ex2.cpp)
target_compile_features(exception_ex2 PRIVATE cxx_std_23)

add_executable(exception_ex3)
target_sources(exception_ex3 PRIVATE exception_ex3.cpp)
target_compile_features(exception_ex3 PRIVATE cxx_std_23)

add_executable(exception_ex4)
target_sources(exception_ex4 PRIVATE exception_ex4.cpp)
target_compile_features(exception_ex4 PRIVATE cxx_std_23)

add_executable(exception_ex5)
target_sources(exception_ex5 PRIVATE exception_ex5.cpp)
target_compile_features(exception_ex5 PRIVATE cxx_std_23)

add_executable(exception_ex6)
target_sources(exception_ex6 PRIVATE exception_ex6.cpp)
target_compile_features(exception_ex6 PRIVATE cxx_std_23)

add_executable(exception_ex7)
target_sources(exception_ex7 PRIVATE exception_ex7.cpp)
target_compile_features(exception_ex7 PRIVATE cxx_std_23)

add_executable(ioexception)
target_sources(ioexception PRIVATE ioexception.cpp)
target_compile_features(ioexception PRIVATE cxx_std_23)

add_executable(constclass)
target_sources(constclass PRIVATE constclass.cpp)
target_compile_features(constclass PRIVATE cxx_std_23)

add_executable(functiontryblock)
target_sources(functiontryblock PRIVATE functiontryblock.cpp)
target_compile_features(functiontryblock PRIVATE cxx_std_23)

add_executable(constructexception)
target_sources(constructexception PRIVATE constructexception.cpp)
target_compile_features(constructexception PRIVATE cxx_std_23)

add_executable(constructdelegateexception)
target_sources(constructdelegateexception PRIVATE constructdelegateexception.cpp)
target_compile_features(constructdelegateexception PRIVATE cxx_std_23)

add_executable(collapse)
target_sources(collapse PRIVATE collapse.cpp)
target_compile_features(collapse PRIVATE cxx_std_23)

install(TARGETS exception_ex1 exception_ex2 exception_ex3 exception_ex4 exception_ex5
    exception_ex6 exception_ex7 ioexception constclass functiontryblock constructexception
    constructdelegateexception collapse
DESTINATION chapter10)
