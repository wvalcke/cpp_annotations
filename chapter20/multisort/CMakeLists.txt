cmake_minimum_required(VERSION 3.20)

add_executable(multisort)
target_sources(multisort PRIVATE data.cc display.cc main.cc newtask.cc partition.cc pushtask.cc readdata.cc
    scheduler.cc wip.cc worker.cc workforce.cc
)
target_compile_features(multisort PRIVATE cxx_std_23)
target_link_libraries(multisort semaphorelib)

install(TARGETS multisort
DESTINATION chapter20)
