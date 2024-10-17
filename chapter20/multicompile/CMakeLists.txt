cmake_minimum_required(VERSION 3.20)

add_executable(multicompile)
target_sources(multicompile PRIVATE main.cc data.cc compile.cc newresult.cc newtask.cc nextcommand.cc
    pushresultq.cc results.cc worker.cc workforce.cc jobs.cc)
target_compile_features(multicompile PRIVATE cxx_std_23)
target_link_libraries(multicompile semaphorelib)

install(TARGETS multicompile
DESTINATION chapter20)

install(FILES files.in DESTINATION chapter20)
