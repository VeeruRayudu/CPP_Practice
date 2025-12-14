#include "4887766_MD1_Task1_Vehicle.h"

int main()
{
    Car car("CAR1234", 2020, 4);
    Truck truck("TRK5678", 2018, 3.5);
    ElectricCar eCar("ELE9012", 2022, 92.5);

    Vehicle *arr[3] = {&car, &truck, &eCar};

    for (int i = 0; i < 3; i++)
    {
        std::cout << "\n-------------------------------------------------\n";
        arr[i]->displayInfo();
        arr[i]->runDiagnostics();
    }

    return 0;
}