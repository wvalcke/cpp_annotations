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

add_executable(resultof)
target_sources(resultof PRIVATE resultof.cc)
target_compile_features(resultof PRIVATE cxx_std_23)

add_executable(resultof2)
target_sources(resultof2 PRIVATE resultof2.cc)
target_compile_features(resultof2 PRIVATE cxx_std_23)

add_executable(instantiations)
target_sources(instantiations PRIVATE instantiations.cc)
target_compile_features(instantiations PRIVATE cxx_std_23)

add_executable(boundfriends)
target_sources(boundfriends PRIVATE boundfriends.cc)
target_compile_features(boundfriends PRIVATE cxx_std_23)

add_executable(testspec)
target_sources(testspec PRIVATE testspec.cc)
target_compile_features(testspec PRIVATE cxx_std_23)

add_executable(friendtest1)
target_sources(friendtest1 PRIVATE friendtest1.cc)
target_compile_features(friendtest1 PRIVATE cxx_std_23)

add_executable(friendtest2)
target_sources(friendtest2 PRIVATE friendtest2.cc)
target_compile_features(friendtest2 PRIVATE cxx_std_23)

# Example does not compile (is normal)
add_executable(friendtest3)
target_sources(friendtest3 PRIVATE friendtest3.cc)
target_compile_features(friendtest3 PRIVATE cxx_std_23)

add_executable(friendtest4)
target_sources(friendtest4 PRIVATE friendtest4.cc)
target_compile_features(friendtest4 PRIVATE cxx_std_23)

add_executable(friendtest5)
target_sources(friendtest5 PRIVATE friendtest5.cc)
target_compile_features(friendtest5 PRIVATE cxx_std_23)

#add_executable(bounditer2)
#target_sources(bounditer2 PRIVATE bounditer2/main.cc)
#target_compile_features(bounditer2 PRIVATE cxx_std_23)

add_executable(bounditer3)
target_sources(bounditer3 PRIVATE bounditer3/main.cc)
target_compile_features(bounditer3 PRIVATE cxx_std_23)

add_executable(template2concrete)
target_sources(template2concrete PRIVATE template2concrete.cc)
target_compile_features(template2concrete PRIVATE cxx_std_23)

add_executable(template2template)
target_sources(template2template PRIVATE template2template.cc)
target_compile_features(template2template PRIVATE cxx_std_23)

add_executable(staticpolymorphism)
target_sources(staticpolymorphism PRIVATE staticpolymorphism/polymorph.cc)
target_compile_features(staticpolymorphism PRIVATE cxx_std_23)

add_executable(nesting)
target_sources(nesting PRIVATE nesting1.cc)
target_compile_features(nesting PRIVATE cxx_std_23)

add_subdirectory(stringptrs)

add_executable(variadicsizeof)
target_sources(variadicsizeof PRIVATE variadicsizeof.cc)
target_compile_features(variadicsizeof PRIVATE cxx_std_23)

add_executable(derive1)
target_sources(derive1 PRIVATE derive1.cc)
target_compile_features(derive1 PRIVATE cxx_std_23)

install(TARGETS deducetype cirque extern genlambda genlambda2 cirquevector cirquepartial
    matrix variadic forwardtestch22 multibaseclass countnontype foldexpression tupletest
    bindings resultof resultof2 instantiations boundfriends testspec friendtest1
    friendtest2 friendtest4 friendtest5
    bounditer3 template2concrete template2template staticpolymorphism
    nesting variadicsizeof derive1
DESTINATION chapter22)
