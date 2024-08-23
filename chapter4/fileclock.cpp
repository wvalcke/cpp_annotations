#include <iostream>
#include <chrono>
#include <filesystem>

using namespace std;
using namespace chrono;
using namespace filesystem;

int main(int argc, char* argv[])
{
    time_t seconds = system_clock::to_time_t(
                    __file_clock::to_sys(last_write_time("testfile.txt"))
                );

    cout << "testfile.txt last (UTC) write time: " <<
             put_time(gmtime(&seconds), "%c") << '\n';    
    cout << "testfile.txt last (Local time) write time: " <<
             put_time(localtime(&seconds), "%c") << '\n';    

}
