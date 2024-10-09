cmake_minimum_required(VERSION 3.20)

add_executable(hello)
target_sources(hello PRIVATE hello.cc)
target_compile_features(hello PRIVATE cxx_std_23)

add_executable(threadargs_wva)
target_sources(threadargs_wva PRIVATE threadargs_wva.cc)
target_compile_features(threadargs_wva PRIVATE cxx_std_23)

add_executable(threadargs)
target_sources(threadargs PRIVATE threadargs.cc)
target_compile_features(threadargs PRIVATE cxx_std_23)

add_executable(memberthreads)
target_sources(memberthreads PRIVATE memberthreads.cc)
target_compile_features(memberthreads PRIVATE cxx_std_23)

add_executable(locals)
target_sources(locals PRIVATE locals.cc)
target_compile_features(locals PRIVATE cxx_std_23)

add_executable(functorthread)
target_sources(functorthread PRIVATE functorthread.cc)
target_compile_features(functorthread PRIVATE cxx_std_23)

add_executable(threads2)
target_sources(threads2 PRIVATE threads2.cc)
target_compile_features(threads2 PRIVATE cxx_std_23)

install(TARGETS hello threadargs_wva threadargs memberthreads locals functorthread
    threads2
DESTINATION chapter20)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
