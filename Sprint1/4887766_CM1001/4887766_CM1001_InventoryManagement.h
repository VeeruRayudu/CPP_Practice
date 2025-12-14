#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H
#include <string>

class InventoryManagement{
    private:
    std::string m_description_of_product;
    int m_balance_stock;
    int m_productCode;

    public:
    //constructors
    InventoryManagement(int balance_stock_);     //default
    InventoryManagement(std::string description_of_product_, int balance_stock_, int productCode_);      //parameterized

    ~InventoryManagement();

    //getter
    int getProductCode(){ return m_productCode; }

    //utility function
    void purchase(int stockQuantity);
    void sale(int saleQuantity);
};

void search(InventoryManagement array[], int size, int pCode);

#endif