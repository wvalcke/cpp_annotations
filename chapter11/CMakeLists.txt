cmake_minimum_required(VERSION 3.20)

add_executable(intarray)
target_sources(intarray PRIVATE intarray.cc mainintarray.cc)
target_compile_features(intarray PRIVATE cxx_std_23)

add_executable(multiindex)
target_sources(multiindex PRIVATE multiindex.cc)
target_compile_features(multiindex PRIVATE cxx_std_23)

add_executable(byte_ex)
target_sources(byte_ex PRIVATE byte.cc)
target_compile_features(byte_ex PRIVATE cxx_std_23)

add_executable(prefixpostfix)
target_sources(prefixpostfix PRIVATE prefixpostfix.cpp)
target_compile_features(prefixpostfix PRIVATE cxx_std_23)

add_executable(prefixpostfix2)
target_sources(prefixpostfix2 PRIVATE prefixpostfix2.cpp)
target_compile_features(prefixpostfix2 PRIVATE cxx_std_23)

add_executable(binaryrvalue)
target_sources(binaryrvalue PRIVATE binaryrvalue.cpp)
target_compile_features(binaryrvalue PRIVATE cxx_std_23)

add_executable(binaryrvalue2)
target_sources(binaryrvalue2 PRIVATE binaryrvalue2.cpp)
target_compile_features(binaryrvalue2 PRIVATE cxx_std_23)

add_executable(binaryrvalue3)
target_sources(binaryrvalue3 PRIVATE binaryrvalue3.cpp)
target_compile_features(binaryrvalue3 PRIVATE cxx_std_23)

add_executable(stringconversionerror)
target_sources(stringconversionerror PRIVATE stringconversionerror.cc)
target_compile_features(stringconversionerror PRIVATE cxx_std_23)

add_executable(refbinding1)
target_sources(refbinding1 PRIVATE refbinding1.cc)
target_compile_features(refbinding1 PRIVATE cxx_std_23)

add_executable(refbinding2)
target_sources(refbinding2 PRIVATE refbinding2.cc)
target_compile_features(refbinding2 PRIVATE cxx_std_23)

add_executable(refbinding3)
target_sources(refbinding3 PRIVATE refbinding3.cc)
target_compile_features(refbinding3 PRIVATE cxx_std_23)

add_executable(newoverload)
target_sources(newoverload PRIVATE newoverload.cpp)
target_compile_features(newoverload PRIVATE cxx_std_23)

add_executable(newoverload2)
target_sources(newoverload2 PRIVATE newoverload2.cpp)
target_compile_features(newoverload2 PRIVATE cxx_std_23)

add_executable(newoverload3)
target_sources(newoverload3 PRIVATE newoverload3.cpp)
target_compile_features(newoverload3 PRIVATE cxx_std_23)

add_executable(manipulator)
target_sources(manipulator PRIVATE manipulator.cpp)
target_compile_features(manipulator PRIVATE cxx_std_23)

add_executable(manipmatrix)
target_sources(manipmatrix PRIVATE manipmatrix.cpp)
target_compile_features(manipmatrix PRIVATE cxx_std_23)

add_executable(lambdatest)
target_sources(lambdatest PRIVATE lambdatest.cpp)
target_compile_features(lambdatest PRIVATE cxx_std_23)

add_executable(ipaddr)
target_sources(ipaddr PRIVATE ipaddr.cpp)
target_compile_features(ipaddr PRIVATE cxx_std_23)

install(TARGETS intarray multiindex stringconversionerror byte_ex prefixpostfix prefixpostfix2 
    binaryrvalue binaryrvalue2 binaryrvalue3 refbinding1 refbinding2 refbinding3
    newoverload newoverload2 newoverload3 manipulator manipmatrix lambdatest ipaddr
DESTINATION chapter11)
