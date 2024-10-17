cmake_minimum_required(VERSION 3.20)

add_executable(declval)
target_sources(declval PRIVATE declval.cc)
target_compile_features(declval PRIVATE cxx_std_23)

add_executable(latereturntype)
target_sources(latereturntype PRIVATE latereturntype.cc)
target_compile_features(latereturntype PRIVATE cxx_std_23)

add_executable(refwrap)
target_sources(refwrap PRIVATE refwrap.cc)
target_compile_features(refwrap PRIVATE cxx_std_23)

add_executable(local_anonymtype)
target_sources(local_anonymtype PRIVATE local_anonymtype.cc)
target_compile_features(local_anonymtype PRIVATE cxx_std_23)

install(TARGETS declval latereturntype refwrap local_anonymtype
DESTINATION chapter21)
