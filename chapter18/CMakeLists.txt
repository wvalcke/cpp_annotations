cmake_minimum_required(VERSION 3.20)

add_executable(sort)
target_sources(sort PRIVATE sort.cc)
target_compile_features(sort PRIVATE cxx_std_23)

add_executable(plus)
target_sources(plus PRIVATE plus.cc)
target_compile_features(plus PRIVATE cxx_std_23)

add_executable(plusaccumulate)
target_sources(plusaccumulate PRIVATE plusaccumulate.cc)
target_compile_features(plusaccumulate PRIVATE cxx_std_23)

add_executable(strcasecmp)
target_sources(strcasecmp PRIVATE strcasecmp.cc)
target_compile_features(strcasecmp PRIVATE cxx_std_23)

add_executable(classtypeplus)
target_sources(classtypeplus PRIVATE classtypeplus.cc)
target_compile_features(classtypeplus PRIVATE cxx_std_23)

add_executable(negate)
target_sources(negate PRIVATE negate.cc)
target_compile_features(negate PRIVATE cxx_std_23)

add_executable(notprog)
target_sources(notprog PRIVATE not.cc)
target_compile_features(notprog PRIVATE cxx_std_23)

add_executable(iterator)
target_sources(iterator PRIVATE iterator.cc)
target_compile_features(iterator PRIVATE cxx_std_23)

add_executable(constiterator)
target_sources(constiterator PRIVATE constiterator.cc)
target_compile_features(constiterator PRIVATE cxx_std_23)

add_executable(distance)
target_sources(distance PRIVATE distance.cc)
target_compile_features(distance PRIVATE cxx_std_23)

add_executable(backinserter)
target_sources(backinserter PRIVATE backinserter.cc)
target_compile_features(backinserter PRIVATE cxx_std_23)

add_executable(istreamiterator)
target_sources(istreamiterator PRIVATE istreamiterator.cc)
target_compile_features(istreamiterator PRIVATE cxx_std_23)

add_executable(ostreamiterator)
target_sources(ostreamiterator PRIVATE ostreamiterator.cc)
target_compile_features(ostreamiterator PRIVATE cxx_std_23)

add_executable(streambufiter)
target_sources(streambufiter PRIVATE streambufiter.cc)
target_compile_features(streambufiter PRIVATE cxx_std_23)

add_executable(moveiter)
target_sources(moveiter PRIVATE moveiter.cc)
target_compile_features(moveiter PRIVATE cxx_std_23)

add_executable(uniqueother)
target_sources(uniqueother PRIVATE uniqueother.cc)
target_compile_features(uniqueother PRIVATE cxx_std_23)

add_executable(deleter)
target_sources(deleter PRIVATE deleter.cc)
target_compile_features(deleter PRIVATE cxx_std_23)

add_executable(insertcpp)
target_sources(insertcpp PRIVATE insertcpp.cc)
target_compile_features(insertcpp PRIVATE cxx_std_23)

add_executable(sharedinsert)
target_sources(sharedinsert PRIVATE sharedinsert.cc)
target_compile_features(sharedinsert PRIVATE cxx_std_23)

add_executable(sharedderivedtest)
target_sources(sharedderivedtest PRIVATE sharedderivedtest.cc)
target_compile_features(sharedderivedtest PRIVATE cxx_std_23)

add_executable(tie)
target_sources(tie PRIVATE tie.cc)
target_compile_features(tie PRIVATE cxx_std_23)

add_executable(optional)
target_sources(optional PRIVATE optional.cc)
target_compile_features(optional PRIVATE cxx_std_23)

add_executable(optionalemplace)
target_sources(optionalemplace PRIVATE optionalemplace.cc)
target_compile_features(optionalemplace PRIVATE cxx_std_23)

install(TARGETS sort plus plusaccumulate strcasecmp classtypeplus negate notprog iterator
    constiterator distance backinserter istreamiterator ostreamiterator streambufiter
    moveiter uniqueother deleter insertcpp sharedinsert sharedderivedtest
    tie optional optionalemplace
DESTINATION chapter18)

#install(FILES nstrings.cc DESTINATION chapter13)
