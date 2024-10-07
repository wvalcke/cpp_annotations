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

add_executable(copy_copyif)
target_sources(copy_copyif PRIVATE copy.cc)
target_compile_features(copy_copyif PRIVATE cxx_std_23)

add_executable(copybackward)
target_sources(copybackward PRIVATE copybackward.cc)
target_compile_features(copybackward PRIVATE cxx_std_23)

add_executable(count_countif)
target_sources(count_countif PRIVATE count.cc)
target_compile_features(count_countif PRIVATE cxx_std_23)

add_executable(equal)
target_sources(equal PRIVATE equal.cc)
target_compile_features(equal PRIVATE cxx_std_23)

add_executable(equalrange)
target_sources(equalrange PRIVATE equalrange.cc)
target_compile_features(equalrange PRIVATE cxx_std_23)

add_executable(exchange)
target_sources(exchange PRIVATE exchange.cc)
target_compile_features(exchange PRIVATE cxx_std_23)

add_executable(fill)
target_sources(fill PRIVATE fill.cc)
target_compile_features(fill PRIVATE cxx_std_23)

add_executable(find)
target_sources(find PRIVATE find.cc)
target_compile_features(find PRIVATE cxx_std_23)

install(TARGETS accumulate adjacentdifference adjacentfind allof beginend
    binarysearch copy_copyif copybackward count_countif equal equalrange exchange
    fill find
DESTINATION chapter19)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
