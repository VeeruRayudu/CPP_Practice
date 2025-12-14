#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <stdexcept>
#include <string>

class Inventory{
    private:
    std::string m_productDescription;
    int m_balanceStock;
    int m_productCode;

    public:
    //constructors
    Inventory(); //default
    Inventory(int balanceStock_, int productCode_); //parameterized

    //getter
    int getProductCode();

    //utility methods
    void purchase(int stockQuantity);
    void sale(int saleQuntity);
    void displayInfo();

};

//gloabal function
void search(Inventory arr[], int size, int productCode_);

#endif