#include<iostream>
#include "Veera_Sept26_task3_HugeInt.h"

int main()
{
    HugeInt n1(7654321);
    HugeInt n2(7891234);
    HugeInt n3("99999999999999999999999999999");
    HugeInt n4("1");
    HugeInt n5;

    std::cout<<"n1 is "<<n1<<"\nn2 is "<<n2<< "\nn3 is " << n3 << "\nn4 is "<<n4<< "\nn5 is "<<n5<<"\n\n";

    //addition
    n5 = n1 + n2;
    cout << n1 << " + " << n2 << " = " << n5 << "\n\n";

    cout << n3 << " + " << n4 << "\n= " << (n3 + n4) << "\n\n";

    n5 = n1 + 9;
    cout << n1 << " + " << 9 << " = " << n5 << "\n\n";

    n5 = n2 + "10000";
    cout << n2 << " + " << "10000" << " = " << n5 << endl;

    //subtraction
    HugeInt n6(1000);
    HugeInt n7(250);
    n5 = n6 - n7;
    cout << "\n" << n6 << " - " << n7 << " = " << n5 << endl;

    //multiplication
    HugeInt n8(123);
    HugeInt n9(4);
    n5 = n8 * n9;
    cout << "\n" << n8 << " * " << n9 << " = " << n5 << endl;

    n5 = n8 * 2;
    cout << n8 << " * " << 2 << " = " << n5 << endl;

    //division
    HugeInt n10(100);
    HugeInt n11(25);
    n5 = n10 / n11;
    cout << "\n" << n10 << " / " << n11 << " = " << n5 << endl;

    n5 = n10 / 10;
    cout << n10 << " / " << 10 << " = " << n5 << endl;

    //relational operators
    cout << "\nRelational operators:" << endl;
    cout << n8 << " == " << n9 << ": " << (n8 == n9 ? "true" : "false") << endl;
    cout << n8 << " != " << n9 << ": " << (n8 != n9 ? "true" : "false") << endl;
    cout << n8 << " < " << n9 << ": " << (n8 < n9 ? "true" : "false") << endl;
    cout << n8 << " > " << n9 << ": " << (n8 > n9 ? "true" : "false") << endl;
    cout << n8 << " <= " << n9 << ": " << (n8 <= n9 ? "true" : "false") << endl;
    cout << n8 << " >= " << n9 << ": " << (n8 >= n9 ? "true" : "false") << endl;

    //equal numbers
    HugeInt n12(123);
    cout << "\n" << n8 << " == " << n12 << ": " << (n8 == n12 ? "true" : "false") << endl;

    return 0;
}