cmake_minimum_required(VERSION 3.20)

add_executable(allocator)
target_sources(allocator PRIVATE allocator.cpp)
target_compile_features(allocator PRIVATE cxx_std_23)

add_executable(swapvector)
target_sources(swapvector PRIVATE swapvector.cpp)
target_compile_features(swapvector PRIVATE cxx_std_23)

add_executable(mergelist)
target_sources(mergelist PRIVATE mergelist.cpp)
target_compile_features(mergelist PRIVATE cxx_std_23)

add_executable(removelist)
target_sources(removelist PRIVATE removelist.cpp)
target_compile_features(removelist PRIVATE cxx_std_23)

add_executable(listsplice)
target_sources(listsplice PRIVATE listsplice.cpp)
target_compile_features(listsplice PRIVATE cxx_std_23)

add_executable(uniquelist)
target_sources(uniquelist PRIVATE uniquelist.cpp)
target_compile_features(uniquelist PRIVATE cxx_std_23)

add_executable(pqueue)
target_sources(pqueue PRIVATE pqueue.cpp)
target_compile_features(pqueue PRIVATE cxx_std_23)

add_executable(pqueuesorted)
target_sources(pqueuesorted PRIVATE pqueuesorted.cpp)
target_compile_features(pqueuesorted PRIVATE cxx_std_23)

add_executable(maptest)
target_sources(maptest PRIVATE maptest.cpp)
target_compile_features(maptest PRIVATE cxx_std_23)

add_executable(findinmap)
target_sources(findinmap PRIVATE findinmap.cpp)
target_compile_features(findinmap PRIVATE cxx_std_23)

add_executable(insertinmap)
target_sources(insertinmap PRIVATE insertinmap.cpp)
target_compile_features(insertinmap PRIVATE cxx_std_23)

add_executable(mapbound)
target_sources(mapbound PRIVATE mapbound.cpp)
target_compile_features(mapbound PRIVATE cxx_std_23)

add_executable(simplemap)
target_sources(simplemap PRIVATE simplemap.cpp)
target_compile_features(simplemap PRIVATE cxx_std_23)

add_executable(multimapbound)
target_sources(multimapbound PRIVATE multimapbound.cpp)
target_compile_features(multimapbound PRIVATE cxx_std_23)

add_executable(multisetbound)
target_sources(multisetbound PRIVATE multisetbound.cpp)
target_compile_features(multisetbound PRIVATE cxx_std_23)

add_executable(unordered_map)
target_sources(unordered_map PRIVATE unordered_map.cpp)
target_compile_features(unordered_map PRIVATE cxx_std_23)

add_executable(unordered_map2)
target_sources(unordered_map2 PRIVATE unordered_map2.cpp)
target_compile_features(unordered_map2 PRIVATE cxx_std_23)

add_executable(complexnum)
target_sources(complexnum PRIVATE complexnum.cpp)
target_compile_features(complexnum PRIVATE cxx_std_23)

install(TARGETS allocator swapvector mergelist removelist listsplice uniquelist pqueue
    pqueuesorted maptest findinmap insertinmap mapbound simplemap multimapbound multisetbound
    unordered_map unordered_map2 complexnum
DESTINATION chapter12)
