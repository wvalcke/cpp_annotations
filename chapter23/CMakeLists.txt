cmake_minimum_required(VERSION 3.20)

add_executable(basename2)
target_sources(basename2 PRIVATE basename2.cc)
target_compile_features(basename2 PRIVATE cxx_std_23)

add_executable(templatekeyword)
target_sources(templatekeyword PRIVATE templatekeyword.cc)
target_compile_features(templatekeyword PRIVATE cxx_std_23)

add_executable(templatekeyword2)
target_sources(templatekeyword2 PRIVATE templatekeyword2.cc)
target_compile_features(templatekeyword2 PRIVATE cxx_std_23)

add_executable(templatekeyword3)
target_sources(templatekeyword3 PRIVATE templatekeyword3.cc)
target_compile_features(templatekeyword3 PRIVATE cxx_std_23)

add_executable(inttype)
target_sources(inttype PRIVATE inttype.cc)
target_compile_features(inttype PRIVATE cxx_std_23)

add_executable(storagepoly)
target_sources(storagepoly PRIVATE storagepoly.cc)
target_compile_features(storagepoly PRIVATE cxx_std_23)

add_executable(storagepoly2)
target_sources(storagepoly2 PRIVATE storagepoly2.cc)
target_compile_features(storagepoly2 PRIVATE cxx_std_23)

add_executable(factorial)
target_sources(factorial PRIVATE factorial.cc)
target_compile_features(factorial PRIVATE cxx_std_23)

add_executable(miles)
target_sources(miles PRIVATE miles.cc)
target_compile_features(miles PRIVATE cxx_std_23)

add_executable(alloctest)
target_sources(alloctest PRIVATE alloctest.cc)
target_compile_features(alloctest PRIVATE cxx_std_23)

add_executable(storage)
target_sources(storage PRIVATE storage.cc)
target_compile_features(storage PRIVATE cxx_std_23)

add_executable(structbypolicy)
target_sources(structbypolicy PRIVATE structbypolicy.cc)
target_compile_features(structbypolicy PRIVATE cxx_std_23)

add_executable(aliastemplate)
target_sources(aliastemplate PRIVATE aliastemplate.cc)
target_compile_features(aliastemplate PRIVATE cxx_std_23)

add_executable(basictraits)
target_sources(basictraits PRIVATE basictraits.cc)
target_compile_features(basictraits PRIVATE cxx_std_23)

install(TARGETS basename2 templatekeyword templatekeyword2 templatekeyword3 inttype
    storagepoly storagepoly2 factorial miles alloctest storage structbypolicy
    aliastemplate basictraits
DESTINATION chapter23)
