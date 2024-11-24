cmake_minimum_required(VERSION 3.20)

add_executable(fib)
target_sources(fib PRIVATE fib.cc)
target_compile_features(fib PRIVATE cxx_std_23)

add_executable(fibcoro)
target_sources(fibcoro PRIVATE fibcoro.cc)
target_compile_features(fibcoro PRIVATE cxx_std_23)

add_executable(readbinary)
target_sources(readbinary PRIVATE readbinary/floats/coread.cc readbinary/floats/cowrite.cc 
readbinary/floats/data.cc readbinary/floats/floats1.cc readbinary/floats/read.cc 
readbinary/floats/write.cc readbinary/reader/next.cc readbinary/writer/next.cc
readbinary/usage.cc readbinary/handle.cc readbinary/main.cc)
target_compile_features(readbinary PRIVATE cxx_std_23)

add_executable(fibocorowait)
target_sources(fibocorowait PRIVATE fibocoroawaiter/main.cc fibocoroawaiter/fibocoroutine.cc
fibocoroawaiter/fibo/next.cc fibocoroawaiter/fibo/suspendalways.cc
fibocoroawaiter/awaiter/awaitsuspend.cc
)
target_compile_features(fibocorowait PRIVATE cxx_std_23)

add_executable(fsa)
target_sources(fsa PRIVATE fsa/main.cc fsa/start/costart.cc fsa/start/data.cc
fsa/start/destructor.cc fsa/start/go.cc fsa/start/start1.cc fsa/letter/coletter.cc
fsa/letter/data.cc fsa/letter/destructor.cc fsa/letter/letter1.cc
fsa/done/codone.cc fsa/done/data.cc fsa/done/destructor.cc fsa/done/done1.cc
fsa/digit/codigit.cc fsa/digit/data.cc fsa/digit/destructor.cc fsa/digit/digit1.cc
)
target_compile_features(fsa PRIVATE cxx_std_23)

add_executable(recursive)
target_sources(recursive PRIVATE recursive/main.cc recursive/recursivecoro.cc
recursive/recursive/state.cc recursive/recursive/recursive.cc
)
target_compile_features(recursive PRIVATE cxx_std_23)

add_executable(recursive2)
target_sources(recursive2 PRIVATE recursive2/main.cc recursive2/recursivecoro.cc
recursive2/fibocoro.cc
recursive2/recursive/state.cc recursive2/recursive/recursive.cc
recursive2/fibo/fibo.cc recursive2/fibo/state.cc
)
target_compile_features(recursive2 PRIVATE cxx_std_23)

add_executable(coroiter)
target_sources(coroiter PRIVATE coroiter/main.cc coroiter/recursivecoro.cc
coroiter/fibocoro.cc coroiter/recursive/iterator.cc coroiter/recursive/recursive.cc
coroiter/recursive/state.cc coroiter/fibo/fibo.cc coroiter/fibo/state.cc
)
target_compile_features(coroiter PRIVATE cxx_std_23)

add_executable(recursivedir)
target_sources(recursivedir PRIVATE dir/main.cc dir/dir/dir1.cc dir/dir/entry.cc)
target_compile_features(recursivedir PRIVATE cxx_std_23)

add_executable(corodir)
target_sources(corodir PRIVATE corodir/main.cc)
target_compile_features(corodir PRIVATE cxx_std_23)

install(TARGETS fib fibcoro readbinary fibocorowait fsa recursive recursive2
coroiter recursivedir corodir
    
DESTINATION chapter24)
