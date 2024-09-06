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

install(TARGETS intarray multiindex stringconversionerror byte_ex prefixpostfix prefixpostfix2 
    binaryrvalue binaryrvalue2 binaryrvalue3
DESTINATION chapter11)
