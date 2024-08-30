cmake_minimum_required(VERSION 3.20)

add_executable(statusflags)
target_sources(statusflags PRIVATE statusflags.cpp)
target_compile_features(statusflags PRIVATE cxx_std_23)

add_executable(align)
target_sources(align PRIVATE align.cpp)
target_compile_features(align PRIVATE cxx_std_23)

add_executable(isopen)
target_sources(isopen PRIVATE isopen.cpp)
target_compile_features(isopen PRIVATE cxx_std_23)

add_executable(strstream)
target_sources(strstream PRIVATE strstream.cpp)
target_compile_features(strstream PRIVATE cxx_std_23)

add_executable(localtime)
target_sources(localtime PRIVATE localtime.cpp)
target_compile_features(localtime PRIVATE cxx_std_23)

add_executable(seekinput)
target_sources(seekinput PRIVATE seekinput.cpp)
target_compile_features(seekinput PRIVATE cxx_std_23)

add_executable(readdouble)
target_sources(readdouble PRIVATE readdouble.cpp)
target_compile_features(readdouble PRIVATE cxx_std_23)

add_executable(inputstring)
target_sources(inputstring PRIVATE inputstring.cpp)
target_compile_features(inputstring PRIVATE cxx_std_23)

add_executable(copyinput)
target_sources(copyinput PRIVATE copyinput.cpp)
target_compile_features(copyinput PRIVATE cxx_std_23)

add_executable(skipline)
target_sources(skipline PRIVATE skipline.cpp)
target_compile_features(skipline PRIVATE cxx_std_23)

add_executable(tietest)
target_sources(tietest PRIVATE tietest.cpp)
target_compile_features(tietest PRIVATE cxx_std_23)

add_executable(movestream)
target_sources(movestream PRIVATE movestream.cpp)
target_compile_features(movestream PRIVATE cxx_std_23)

add_executable(movetest)
target_sources(movetest PRIVATE movetest.cpp)
target_compile_features(movetest PRIVATE cxx_std_23)

add_executable(redirect)
target_sources(redirect PRIVATE redirect.cpp)
target_compile_features(redirect PRIVATE cxx_std_23)

add_executable(dbsample)
target_sources(dbsample PRIVATE dbsample.cpp)
target_compile_features(dbsample PRIVATE cxx_std_23)

add_executable(checkstatus)
target_sources(checkstatus PRIVATE checkstatus.cpp)
target_compile_features(checkstatus PRIVATE cxx_std_23)

add_executable(readwrite2)
target_sources(readwrite2 PRIVATE readwrite2.cpp)
target_compile_features(readwrite2 PRIVATE cxx_std_23)

add_executable(dbsample2)
target_sources(dbsample2 PRIVATE dbsample2.cpp)
target_compile_features(dbsample2 PRIVATE cxx_std_23)

add_executable(reusestringstream)
target_sources(reusestringstream PRIVATE reusestringstream.cpp)
target_compile_features(reusestringstream PRIVATE cxx_std_23)

install(TARGETS statusflags align isopen strstream localtime seekinput readdouble
    inputstring copyinput skipline tietest movestream movetest redirect
    dbsample checkstatus readwrite2 dbsample2 reusestringstream
DESTINATION chapter6)
install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter6)
