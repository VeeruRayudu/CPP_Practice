#include <iostream>
#include "Veera_Sept24_task1_Time.h"

int main()
{
    ModifiedTime t1(12, 59, 58);
    std::cout << "Starting time: ";
    t1.printStandard();
    std::cout << std::endl;

    for (int i = 0; i < 5; i++)
    {
        t1.tick();
        t1.printStandard();
        std::cout << std::endl;
    }

    std::cout << "\n---Testing next hour------\n";
    ModifiedTime t2(1, 59, 58);
    for (int i = 0; i < 5; i++)
    {
        t2.tick();
        t2.printStandard();
        std::cout << std::endl;
    }

    std::cout << "\n---Testing next day---\n";
    ModifiedTime t3(23, 59, 58);
    for (int i = 0; i < 5; i++)
    {
        t3.tick();
        t3.printStandard();
        std::cout << std::endl;
    }

    return 0;
}