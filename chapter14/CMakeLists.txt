cmake_minimum_required(VERSION 3.20)

add_executable(notvirtual)
target_sources(notvirtual PRIVATE notvirtual.cc)
target_compile_features(notvirtual PRIVATE cxx_std_23)

add_executable(purevirtimpl)
target_sources(purevirtimpl PRIVATE purevirtualimp.cc)
target_compile_features(purevirtimpl PRIVATE cxx_std_23)

install(TARGETS purevirtimpl notvirtual
DESTINATION chapter14)

#install(FILES nstrings.cc DESTINATION chapter13)
