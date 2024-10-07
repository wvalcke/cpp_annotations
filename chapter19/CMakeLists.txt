cmake_minimum_required(VERSION 3.20)

add_executable(accumulate)
target_sources(accumulate PRIVATE accumulate.cc)
target_compile_features(accumulate PRIVATE cxx_std_23)

add_executable(adjacentdifference)
target_sources(adjacentdifference PRIVATE adjacentdifference.cc)
target_compile_features(adjacentdifference PRIVATE cxx_std_23)

add_executable(adjacentfind)
target_sources(adjacentfind PRIVATE adjacentfind.cc)
target_compile_features(adjacentfind PRIVATE cxx_std_23)

add_executable(allof)
target_sources(allof PRIVATE allof.cc)
target_compile_features(allof PRIVATE cxx_std_23)

add_executable(beginend)
target_sources(beginend PRIVATE beginend.cc)
target_compile_features(beginend PRIVATE cxx_std_23)

add_executable(binarysearch)
target_sources(binarysearch PRIVATE binarysearch.cc)
target_compile_features(binarysearch PRIVATE cxx_std_23)

install(TARGETS accumulate adjacentdifference adjacentfind allof beginend
    binarysearch
DESTINATION chapter19)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
