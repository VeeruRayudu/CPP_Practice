#include <iostream>
#include "4887766_CM1001_InventoryManagement.h"

int main(){
    //TC01
    std::cout<<"--------------TC01------------------\n";
    InventoryManagement iobj(30);
    iobj.sale(5);
    iobj.sale(4);
    iobj.purchase(10);
    iobj.sale(25);

    //TC02
    std::cout<<"--------------TC02------------------\n";
    InventoryManagement iobj2(50);
    iobj2.purchase(10);
    iobj2.sale(45);

    //TC03
    std::cout<<"--------------TC03------------------\n";
    InventoryManagement iob1("Household", 100, 50111);
    InventoryManagement iob2("Electronics", 500, 50112);
    InventoryManagement iob3("Sports", 300, 50113);

    InventoryManagement iarr[3] = {iob1, iob2, iob3};
    search(iarr, 3, 50112);
}