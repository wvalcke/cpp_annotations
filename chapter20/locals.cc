#include <iostream>
#include <thread>
#include <string>
#include <chrono>

void threadFun(std::string const &text)
{
    for (size_t iter = 1; iter != 6; ++iter)
    {
        std::cout << text << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::thread safeLocal()
{
    std::string text = "hello world";
    //return std::thread(threadFun, std::string{ text });
    std::thread l_Thread = std::thread(threadFun, std::move(text));
    std::cout << "Local var = " << text << '\n';
    return l_Thread;
}

int main()
{
    std::thread local(safeLocal());
    local.join();
    std::cout << "safeLocal has ended\n";
}
