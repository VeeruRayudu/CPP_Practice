#include <iostream>
#include "4887766_CM1001_InventoryManagement.h"

// constructors
InventoryManagement::InventoryManagement(int balance_stock_ = 26) : m_description_of_product(""), m_balance_stock(balance_stock_), m_productCode(0) {}; // default
InventoryManagement::InventoryManagement(std::string description_of_product_, int balance_stock_, int productCode_) : m_description_of_product(description_of_product_), m_balance_stock(balance_stock_), m_productCode(productCode_) {};               // parameterized

InventoryManagement::~InventoryManagement()
{
    std::cout << "InventoryManagement Destroyed..." << "\n";
}

// Implementing purchase
void InventoryManagement::purchase(int stockQuantity)
{
    m_balance_stock += stockQuantity;
    std::cout << "After purchase stock: " << m_balance_stock << "\n";
}

void InventoryManagement::sale(int saleQuantity)
{
    if ((m_balance_stock - saleQuantity) > 20)
    {
        m_balance_stock -= saleQuantity;
        std::cout << "After sale stock: " << m_balance_stock << "\n";
    }
    else
    {
        std::cout << "Low stock level"<<"\n";
    }
}

void search(InventoryManagement array[], int size, int pCode)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i].getProductCode() == pCode)
        {
            std::cout << "Product Found " << "\n";
            return;
        }
    }
    std::cout << "Product Not Found " << "\n";
}
