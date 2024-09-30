cmake_minimum_required(VERSION 3.20)

add_executable(notvirtual)
target_sources(notvirtual PRIVATE notvirtual.cc)
target_compile_features(notvirtual PRIVATE cxx_std_23)

add_executable(purevirtimpl)
target_sources(purevirtimpl PRIVATE purevirtualimp.cc)
target_compile_features(purevirtimpl PRIVATE cxx_std_23)

add_executable(virtualinherit)
target_sources(virtualinherit PRIVATE virtualinherit.cc)
target_compile_features(virtualinherit PRIVATE cxx_std_23)

add_executable(virtualinherit2)
target_sources(virtualinherit2 PRIVATE virtualinherit2.cc)
target_compile_features(virtualinherit2 PRIVATE cxx_std_23)

add_executable(trucktrailer)
target_sources(trucktrailer PRIVATE trucktrailer.cc)
target_compile_features(trucktrailer PRIVATE cxx_std_23)

add_executable(badcast)
target_sources(badcast PRIVATE badcast.cc)
target_compile_features(badcast PRIVATE cxx_std_23)

install(TARGETS purevirtimpl notvirtual virtualinherit virtualinherit2 trucktrailer badcast
DESTINATION chapter14)

#install(FILES nstrings.cc DESTINATION chapter13)
