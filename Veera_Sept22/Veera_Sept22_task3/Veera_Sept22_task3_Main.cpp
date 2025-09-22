#include<iostream>
#include<string>
#include "Veera_Sept22_task3_Invoice.h"

int main(){

    Invoice invoice1("263F2A", "car windsheild", 2, 1000);
    Invoice invoice2("363H2A", "car tyre", 4, 1500);

    invoice1.printInvoice(invoice1.getInvoiceAmount());
    invoice2.printInvoice(invoice2.getInvoiceAmount());
    


}