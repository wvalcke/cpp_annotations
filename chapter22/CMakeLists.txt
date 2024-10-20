cmake_minimum_required(VERSION 3.20)

add_executable(deducetype)
target_sources(deducetype PRIVATE deducetype.cc)
target_compile_features(deducetype PRIVATE cxx_std_23)

add_executable(cirque)
target_sources(cirque PRIVATE cirque.cc)
target_compile_features(cirque PRIVATE cxx_std_23)

add_executable(extern)
target_sources(extern PRIVATE extern.cc extern2.cc)
target_compile_features(extern PRIVATE cxx_std_23)

add_executable(genlambda)
target_sources(genlambda PRIVATE genlambda.cc)
target_compile_features(genlambda PRIVATE cxx_std_23)

add_executable(genlambda2)
target_sources(genlambda2 PRIVATE genlambda2.cc)
target_compile_features(genlambda2 PRIVATE cxx_std_23)

install(TARGETS deducetype cirque extern genlambda genlambda2
DESTINATION chapter22)
