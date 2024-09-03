cmake_minimum_required(VERSION 3.20)

add_executable(rawbytes)
target_sources(rawbytes PRIVATE rawbytes.cpp)
target_compile_features(rawbytes PRIVATE cxx_std_23)

add_executable(placementnew)
target_sources(placementnew PRIVATE placementnew.cpp)
target_compile_features(placementnew PRIVATE cxx_std_23)

add_executable(destructor)
target_sources(destructor PRIVATE destructor.cpp)
target_compile_features(destructor PRIVATE cxx_std_23)

add_executable(wrapper)
target_sources(wrapper PRIVATE wrapper.cpp)
target_compile_features(wrapper PRIVATE cxx_std_23)

add_executable(newhandler)
target_sources(newhandler PRIVATE newhandler.cpp)
target_compile_features(newhandler PRIVATE cxx_std_23)

add_executable(assignment)
target_sources(assignment PRIVATE assignment.cpp)
target_compile_features(assignment PRIVATE cxx_std_23)

add_executable(copyconstruct)
target_sources(copyconstruct PRIVATE copyconstruct.cpp)
target_compile_features(copyconstruct PRIVATE cxx_std_23)

add_executable(copyconstruct2)
target_sources(copyconstruct2 PRIVATE copyconstruct2.cpp)
target_compile_features(copyconstruct2 PRIVATE cxx_std_23)

add_executable(fastswap)
target_sources(fastswap PRIVATE fastswap.cpp)
target_compile_features(fastswap PRIVATE cxx_std_23)

add_executable(rvalue)
target_sources(rvalue PRIVATE rvalue.cpp)
target_compile_features(rvalue PRIVATE cxx_std_23)

add_executable(rvaluetest)
target_sources(rvaluetest PRIVATE rvaluetest.cpp)
target_compile_features(rvaluetest PRIVATE cxx_std_23)

add_executable(copyconstructsuppress)
target_sources(copyconstructsuppress PRIVATE copyconstructsuppress.cpp)
target_compile_features(copyconstructsuppress PRIVATE cxx_std_23)

install(TARGETS rawbytes placementnew destructor wrapper newhandler assignment
    copyconstruct copyconstruct2 fastswap rvalue rvaluetest copyconstructsuppress
DESTINATION chapter9)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter9)
