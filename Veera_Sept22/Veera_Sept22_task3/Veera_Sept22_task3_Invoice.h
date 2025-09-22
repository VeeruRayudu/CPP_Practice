#ifndef INVOICE_H
#define INVOICE_H
#include<string>

class Invoice{
    private:
    std::string itemNumber;
    std::string itemDescription;
    int itemQuantity;
    int itemPrice;

    public:
    //constructor
    Invoice(std::string number, std::string description, int quantity, int price );

    //setters
    void setItemNumber(std::string number);
    void setItemDescription(std::string description);
    void setItemQuantity(int quantity);
    void setItemPrice(int price);

    //getters
    std::string getItemNumber() const;
    std::string getItemDescription() const;
    int getItemQuantity() const;
    int getItemPrice() const;

    //returns invoice for the qunatity
    int getInvoiceAmount();

    void printInvoice(int invoice) const;
    

};

#endif