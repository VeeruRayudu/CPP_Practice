#include "4887766_CM2001_Battery.h"

int main(){
    //TC1
    std::cout<<"\n-----------------------TC1------------------------\n";
    Battery b1(1, "Type 1", "Manufacturer 1", 1000.0, 12.0);
    Battery b2(2, "Type 2", "Manufacturer 2", 2000.0, 24.0);
    Battery b3(3, "Type 3", "Manufacturer 3", 3000.0, 36.0);
    Battery arr[3] = {b1, b2, b3};
    std::cout<<"Created an array of 3 battery objects"<<"\n";

    //TC2
    std::cout<<"\n-----------------------TC2------------------------\n";
    showAllBatteries(arr, 3);

    //TC3
    std::cout<<"\n-----------------------TC3------------------------\n";
    searchBatteriesByManufacturer(arr, 3, "Manufacturer 1");

    //TC4
    std::cout<<"\n-----------------------TC4------------------------\n";
    searchBatteriesByManufacturer(arr, 3, "Manufacturer 9");

}