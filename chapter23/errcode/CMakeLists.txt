cmake_minimum_required(VERSION 3.20)

add_executable(errcode)
target_sources(errcode PRIVATE main.cc category/data.cc category/equivalent1.cc
    category/equivalent2.cc category/instance.cc category/makeerrorcode.cc
    category/makeerrorcondition.cc category/message.cc category/name.cc
    category/defaulterrorcondition.cc)
target_compile_features(errcode PRIVATE cxx_std_23)

add_executable(systemcat)
target_sources(systemcat PRIVATE systemcat/main.cc)
target_compile_features(systemcat PRIVATE cxx_std_23)

install(TARGETS errcode systemcat
DESTINATION chapter23)
