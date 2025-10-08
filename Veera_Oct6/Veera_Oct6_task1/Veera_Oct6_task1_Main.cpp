#include <iostream>
#include <iomanip>
#include "Veera_Oct6_task1_BasePlusCommissionEmployee.h"

int main() {
    cout << fixed << setprecision(2);

    { // begin new scope
        CommissionEmployee employee1("Bob", "Lewis", "333-33-3333", 5000, .04);
    }

    std::cout<<endl;

    BasePlusCommissionEmployee employee2(
        "Lisa", "Jones", "555-55-5555", 2000, .06, 800);

    std::cout<<endl;

    BasePlusCommissionEmployee employee3(
        "Mark", "Sands", "888-88-8888", 8000, .15, 2000);

    std::cout<<endl;

    return 0;
}
