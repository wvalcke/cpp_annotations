cmake_minimum_required(VERSION 3.20)

add_executable(koenig)
target_sources(koenig PRIVATE koenig.cpp)
target_compile_features(koenig PRIVATE cxx_std_23)

add_executable(koenig2)
target_sources(koenig2 PRIVATE koenig2.cpp)
target_compile_features(koenig2 PRIVATE cxx_std_23)

add_executable(ratio)
target_sources(ratio PRIVATE ratio.cpp)
target_compile_features(ratio PRIVATE cxx_std_23)

add_executable(duration)
target_sources(duration PRIVATE duration.cpp)
target_compile_features(duration PRIVATE cxx_std_23)

add_executable(clock)
target_sources(clock PRIVATE clock.cpp)
target_compile_features(clock PRIVATE cxx_std_23)

add_executable(fileclock)
target_sources(fileclock PRIVATE fileclock.cpp)
target_compile_features(fileclock PRIVATE cxx_std_23)

add_executable(scandir)
target_sources(scandir PRIVATE scandir.cpp)
target_compile_features(scandir PRIVATE cxx_std_23)
