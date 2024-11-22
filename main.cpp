#include "Time.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <memory>

int main()
{

    Time *time1 = new Time(10, 20, 30);
    time1->PrintTime();

    delete time1;

    try
    {
        Time t1(10, 30, 45);
        t1.PrintTime();

        Time t2(25, 61, 100);
        t2.PrintTime();
    }
    catch (const InvalidTimeException &e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
