cmake_minimum_required(VERSION 3.20)

add_executable(bindings)
target_sources(bindings PRIVATE bindings.cc)
target_compile_features(bindings PRIVATE cxx_std_23)

add_executable(byte)
target_sources(byte PRIVATE bindings.cc)
target_compile_features(byte PRIVATE cxx_std_23)

add_executable(initializer)
target_sources(initializer PRIVATE initializer.cc)
target_compile_features(initializer PRIVATE cxx_std_23)

add_executable(structured)
target_sources(structured PRIVATE structured.cc)
target_compile_features(structured PRIVATE cxx_std_23)

add_executable(rvalueref)
target_sources(rvalueref PRIVATE rvalueref.cc)
target_compile_features(rvalueref PRIVATE cxx_std_23)

add_executable(movetest)
target_sources(movetest PRIVATE movetest.cc)
target_compile_features(movetest PRIVATE cxx_std_23)

add_executable(movecons1)
target_sources(movecons1 PRIVATE movecons1.cc)
target_compile_features(movecons1 PRIVATE cxx_std_23)

add_executable(movecons2)
target_sources(movecons2 PRIVATE movecons2.cc)
target_compile_features(movecons2 PRIVATE cxx_std_23)

add_executable(movecons3)
target_sources(movecons3 PRIVATE movecons3.cc)
target_compile_features(movecons3 PRIVATE cxx_std_23)

add_executable(movecons4)
target_sources(movecons4 PRIVATE movecons4.cc)
target_compile_features(movecons4 PRIVATE cxx_std_23)

add_executable(movecons5)
target_sources(movecons5 PRIVATE movecons5.cc)
target_compile_features(movecons5 PRIVATE cxx_std_23)

install(TARGETS bindings byte initializer structured rvalueref movetest
    movecons1 movecons2 movecons3 movecons4 movecons5
DESTINATION chapter3)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
