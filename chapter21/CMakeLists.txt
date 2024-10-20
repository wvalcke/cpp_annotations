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

add_executable(source1)
target_sources(source1 PRIVATE source1.cc main.cc)
target_compile_features(source1 PRIVATE cxx_std_23)

add_executable(source2)
target_sources(source2 PRIVATE source2.cc main.cc)
target_compile_features(source1 PRIVATE cxx_std_23)

add_executable(forwardtest)
target_sources(forwardtest PRIVATE forwardtest.cc)
target_compile_features(forwardtest PRIVATE cxx_std_23)

add_executable(templateconstexpr)
target_sources(templateconstexpr PRIVATE templateconstexpr.cc)
target_compile_features(templateconstexpr PRIVATE cxx_std_23)

add_executable(templatevar)
target_sources(templatevar PRIVATE templatevar.cc)
target_compile_features(templatevar PRIVATE cxx_std_23)

install(TARGETS declval latereturntype refwrap local_anonymtype source1 source2 forwardtest
    templateconstexpr templatevar
DESTINATION chapter21)
