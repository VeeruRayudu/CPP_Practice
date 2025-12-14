#include "4887766_CM2001_Inventory.h"

int main(){
    //TC1
    std::cout<<"\n------------------TC1-------------------\n";
    Inventory inv1(1, 20);
    inv1.displayInfo();

    //TC2
    std::cout<<"\n------------------TC2-------------------\n";
    inv1.purchase(10);

    //TC3
    std::cout<<"\n------------------TC3-------------------\n";
    inv1.sale(5);

    //TC4
    std::cout<<"\n------------------TC4-------------------\n";
    inv1.sale(30);

    //TC5
    std::cout<<"\n------------------TC5-------------------\n";
    Inventory arr[3] = {inv1, Inventory(2,1), Inventory(3,0)};

    //TC6
    std::cout<<"\n------------------TC6-------------------\n";
    search(arr, 3, 1);

    //TC7
    std::cout<<"\n------------------TC7-------------------\n";
    search(arr, 3, 99);

    return 0;
}