#include<string>
#include<iostream>
#include "Veera_Sept22_task3_Invoice.h"

//constructor initialization
Invoice::Invoice(std::string number, std::string description, int quantity, int price){
    setItemNumber(number);
    setItemDescription(description);
    setItemQuantity(quantity);
    setItemPrice(price);
}

//setters
void Invoice::setItemNumber(const std::string number){
    itemNumber = number;
}
void Invoice::setItemDescription(const std::string description){
    itemDescription = description;
}
void Invoice::setItemQuantity(int quantity){
    itemQuantity = quantity;
}
void Invoice::setItemPrice(int price){
    itemPrice = price;
}

//getters
std::string Invoice::getItemNumber() const{
    return itemNumber;
}
std::string Invoice::getItemDescription() const{
    return itemDescription;
}
int Invoice::getItemQuantity() const{
    return itemQuantity;
}
int Invoice::getItemPrice() const{
    return itemPrice;
}

int Invoice::getInvoiceAmount(){

    int invoice = ((getItemQuantity()>0 && getItemPrice()>0) ? (getItemQuantity() * getItemPrice()) : 0); //calculates the invoice

    return invoice;
}

void Invoice::printInvoice(int invoice) const {
    std::cout<<"The invoice for the item: "<<getItemDescription()<<", item number: "<<getItemNumber()<<", item price: "<<getItemPrice()<<" the invoice is --> "<<invoice<<std::endl;
}
