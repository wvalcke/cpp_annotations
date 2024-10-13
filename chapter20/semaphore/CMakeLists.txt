cmake_minimum_required(VERSION 3.20)

add_library(semaphorelib STATIC)
target_sources(semaphorelib PRIVATE increase.cc reduce.cc semaphore1.cc size.cc
)
