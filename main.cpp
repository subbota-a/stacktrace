#include <stdexcept>
#include <iostream>
#include <strstream>
#include <chrono>
#include <boost/stacktrace.hpp>

void foo1()
{
    std::cout << "current stack is\n" << boost::stacktrace::stacktrace() << std::endl;
    throw std::runtime_error("from foo");
}

void show1()
{
    std::cout << "catching\n" << boost::stacktrace::stacktrace::from_current_exception() << std::endl;
}

int main()
{
    try
    {
        foo1();
    }
    catch (std::exception &e)
    {
        show1();
    }
    return 0;
}