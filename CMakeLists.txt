cmake_minimum_required(VERSION 3.20)

project(CPPANNOTATIONS
    VERSION 1.0
    DESCRIPTION CPPANNOTATIONS
    LANGUAGES CXX
)

if(ENABLE_SANITIZER)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address  -fsanitize=leak")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address  -fsanitize=leak")
endif()

find_package(TBB REQUIRED)

if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER3)
add_subdirectory(chapter3)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER4)
add_subdirectory(chapter4)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER5)
add_subdirectory(chapter5)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER6)
add_subdirectory(chapter6)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER7)
add_subdirectory(chapter7)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER8)
add_subdirectory(chapter8)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER9)
add_subdirectory(chapter9)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER10)
add_subdirectory(chapter10)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER11)
add_subdirectory(chapter11)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER12)
add_subdirectory(chapter12)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER13)
add_subdirectory(chapter13)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER14)
add_subdirectory(chapter14)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER16)
add_subdirectory(chapter16)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER17)
add_subdirectory(chapter17)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER18)
add_subdirectory(chapter18)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER19)
add_subdirectory(chapter19)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER20)
add_subdirectory(chapter20)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER21)
add_subdirectory(chapter21)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER22)
add_subdirectory(chapter22)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER23)
add_subdirectory(chapter23)
endif()
if (BUILD_ALL_CHAPTERS OR BUILD_CHAPTER24)
add_subdirectory(chapter24)
endif()
