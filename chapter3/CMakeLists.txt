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

install(TARGETS bindings byte initializer structured rvalueref
DESTINATION chapter3)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
