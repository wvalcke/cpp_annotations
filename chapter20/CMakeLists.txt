cmake_minimum_required(VERSION 3.20)

add_executable(hello)
target_sources(hello PRIVATE hello.cc)
target_compile_features(hello PRIVATE cxx_std_23)

add_executable(threadargs_wva)
target_sources(threadargs_wva PRIVATE threadargs_wva.cc)
target_compile_features(threadargs_wva PRIVATE cxx_std_23)

add_executable(threadargs)
target_sources(threadargs PRIVATE threadargs.cc)
target_compile_features(threadargs PRIVATE cxx_std_23)

add_executable(memberthreads)
target_sources(memberthreads PRIVATE memberthreads.cc)
target_compile_features(memberthreads PRIVATE cxx_std_23)

add_executable(locals)
target_sources(locals PRIVATE locals.cc)
target_compile_features(locals PRIVATE cxx_std_23)

add_executable(functorthread)
target_sources(functorthread PRIVATE functorthread.cc)
target_compile_features(functorthread PRIVATE cxx_std_23)

add_executable(threads2)
target_sources(threads2 PRIVATE threads2.cc)
target_compile_features(threads2 PRIVATE cxx_std_23)

add_executable(detached)
target_sources(detached PRIVATE detached.cc)
target_compile_features(detached PRIVATE cxx_std_23)

add_executable(terminate)
target_sources(terminate PRIVATE terminate.cc)
target_compile_features(terminate PRIVATE cxx_std_23)

add_executable(threadlocal)
target_sources(threadlocal PRIVATE threadlocal.cc)
target_compile_features(threadlocal PRIVATE cxx_std_23)

add_executable(stoptoken)
target_sources(stoptoken PRIVATE stoptoken.cc)
target_compile_features(stoptoken PRIVATE cxx_std_23)

add_executable(stopcallback)
target_sources(stopcallback PRIVATE stopcallback.cc)
target_compile_features(stopcallback PRIVATE cxx_std_23)

add_executable(callonce)
target_sources(callonce PRIVATE callonce.cc)
target_compile_features(callonce PRIVATE cxx_std_23)

add_executable(staticlocal)
target_sources(staticlocal PRIVATE staticlocal.cc)
target_compile_features(staticlocal PRIVATE cxx_std_23)

add_executable(insertguard)
target_sources(insertguard PRIVATE insertguard.cc)
target_compile_features(insertguard PRIVATE cxx_std_23)

add_executable(scopedlock)
target_sources(scopedlock PRIVATE scopedlock.cc)
target_compile_features(scopedlock PRIVATE cxx_std_23)

add_executable(lock)
target_sources(lock PRIVATE lock.cc)
target_compile_features(lock PRIVATE cxx_std_23)

add_executable(events)
target_sources(events PRIVATE events.cc)
target_compile_features(events PRIVATE cxx_std_23)

add_subdirectory(semaphore)
add_subdirectory(multisort)

install(TARGETS hello threadargs_wva threadargs memberthreads locals functorthread
    threads2 detached terminate threadlocal stoptoken stopcallback callonce staticlocal
    insertguard scopedlock lock events
DESTINATION chapter20)
#install(FILES double.bin flags.txt nonewline.txt DESTINATION chapter3)
