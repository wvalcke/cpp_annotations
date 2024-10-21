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

add_executable(cirquevector)
target_sources(cirquevector PRIVATE cirquevector.cc)
target_compile_features(cirquevector PRIVATE cxx_std_23)

add_executable(cirquepartial)
target_sources(cirquepartial PRIVATE cirquepartial.cc)
target_compile_features(cirquepartial PRIVATE cxx_std_23)

add_executable(matrix)
target_sources(matrix PRIVATE matrix.cc)
target_compile_features(matrix PRIVATE cxx_std_23)

add_executable(variadic)
target_sources(variadic PRIVATE variadic.cc)
target_compile_features(variadic PRIVATE cxx_std_23)

add_executable(forwardtestch22)
target_sources(forwardtestch22 PRIVATE forwardtest.cc)
target_compile_features(forwardtestch22 PRIVATE cxx_std_23)

add_executable(multibaseclass)
target_sources(multibaseclass PRIVATE multibaseclass.cc)
target_compile_features(multibaseclass PRIVATE cxx_std_23)

add_executable(countnontype)
target_sources(countnontype PRIVATE countnontype.cc)
target_compile_features(countnontype PRIVATE cxx_std_23)

add_executable(foldexpression)
target_sources(foldexpression PRIVATE foldexpression.cc)
target_compile_features(foldexpression PRIVATE cxx_std_23)

add_executable(tupletest)
target_sources(tupletest PRIVATE tupletest.cc)
target_compile_features(tupletest PRIVATE cxx_std_23)

add_executable(bindings)
target_sources(bindings PRIVATE bindings.cc)
target_compile_features(bindings PRIVATE cxx_std_23)

install(TARGETS deducetype cirque extern genlambda genlambda2 cirquevector cirquepartial
    matrix variadic forwardtestch22 multibaseclass countnontype foldexpression tupletest
    bindings
DESTINATION chapter22)
