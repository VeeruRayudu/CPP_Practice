#include "4887766_CM2001_Inventory.h"

//default constructor initializaton
Inventory::Inventory(): m_productDescription(""), m_balanceStock(20), m_productCode(0) {};

//parameterized constructor initialization
Inventory::Inventory(int productCode_, int balanceStock_): m_productDescription(""),m_productCode(productCode_) {
    if(balanceStock_ >= 20){
        m_balanceStock = balanceStock_;
    }
};

int Inventory::getProductCode(){ return m_productCode; }

//purchase function
void Inventory::purchase(int stockQuantity){
    m_balanceStock += stockQuantity;   //increase stock
    std::cout<<"Current stock after adding "<<stockQuantity<<" quantity: "<<m_balanceStock<<"\n";
}

//sale function
void Inventory::sale(int saleQunatity){
    if((m_balanceStock - saleQunatity) >= 20){
        m_balanceStock -= saleQunatity;        //decrease stock
        std::cout<<"Current stock after sale of "<<saleQunatity<<" quantity: "<<m_balanceStock<<"\n";
    }else{
        std::cout<<"Insufficient stock to fulfill the sale."<<"\n";
    }
}

//displaying inventory details
void Inventory::displayInfo(){
    std::cout<<"Description: "<<m_productDescription<<"\n"
             <<"Stock: "<<m_balanceStock<<"\n"
             <<"Product Code: "<<m_productCode;
}

//search function to check against a given product code
void search(Inventory arr[], int size, int productCode_){
    bool found = false;
    for(int i=0; i<size; i++){
        if(arr[i].getProductCode() == productCode_){
            arr[i].displayInfo();
            found = true;
        }
    }
    if(!found){
        std::cout<<"Product not found for code "<<productCode_<<"\n";
    }
}