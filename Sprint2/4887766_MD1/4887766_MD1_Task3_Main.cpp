#include "4887766_MD1_Task3_Vehicle.h"

int main(){
    Vehicle v1;
    Vehicle v2("Sedan", 2022);
    Vehicle v3("SUV", 2023);

    v1.show();
    v2.show();
    v3.show();

    using VehicleArray = Vehicle*[];

    VehicleArray vehicles = {&v1, &v2, &v3};

    for(auto v : vehicles){
        std::cout<<"\n----------------------------------------\n";
        v->show();
    }

    return 0;
}