#include <iostream>
#include <tuple>
// //unary left fold -- left to right
// template <typename... Args>
// auto sumLU(Args... arg)
// {
//     return (... + arg);     
// }

// //unary right fold -- right to left
// template <typename... Args>
// auto sumRU(Args... arg)
// {
//     return (arg + ...);     
// }

// //binary left fold
// template <typename... Args>
// auto sumLB(Args... arg)
// {
//     return (100 + ... + arg);     
// }

// //binary right fold
// template <typename... Args>
// auto sumRB(Args... arg)
// {
//     return (arg + ... + 100);     
// }

// int main()
// {
//     std::cout << sumLU(1, 2, 3, 4) <<std::endl;
//     std::cout << sumRU(10, 14) <<std::endl;
//     std::cout << sumLU(10, 20, 30, 40, 22, 4, 60, 69) <<std::endl;
//     std::cout << sumLB(10, 20, 30, 40, 22, 4, 60, 69) <<std::endl;
//     std::cout << sumRB(10, 20, 30, 40, 22, 4, 60, 69) <<std::endl;

//     return 0;
// }

// //structred binding -- what it is, structure, std::pair, array, tuple





int main() {
    std::tuple<int, float, std::string> data = {101, 88.5f, "Hello"};

    // auto id = std::get<0>(data);
    // auto temp = std::get<1>(data);
    // auto str = std::get<2>(data);

    auto [id, temp, str] = data;
    std::cout << id << ", " << temp << ", " << str << "\n";

    //copy
    id = 200;
    std::cout << std::get<0>(data) << std::endl;

    //reference
    auto &[id_, temp_, str_] = data;
    id_ = 200;
    std::cout << std::get<0>(data) << std::endl;
}

#include<iostream>
#include<string>
 
struct book
{
    std::string m_name;
    double m_price;
    std::string m_author;    
    int m_pages;
};
 
int main(){
 
    book b1{"Harry Potter",100.0,"K. WIlson", 100};
    book b2{"Garudzhep", 234.2,"K. Patil", 334};
    book b3{"Bhagwadgita", 1000,"M. Vyas", 700};
 
    std::cout<<"\nBook 1 Details: "<<std::endl;
    std::cout<<"Name: "<<b1.m_name<<"  Price: "<<b1.m_price<<"  Author: "<<b1.m_author<<"  Pages: "<<b1.m_pages<<std::endl;
    std::cout<<"\nBook 2 Details: "<<std::endl;
    std::cout<<"Name: "<<b2.m_name<<"  Price: "<<b2.m_price<<"  Author: "<<b2.m_author<<"  Pages: "<<b2.m_pages<<std::endl;
    std::cout<<"\nBook 3 Details: "<<std::endl;
    std::cout<<"Name: "<<b3.m_name<<"  Price: "<<b3.m_price<<"  Author: "<<b3.m_author<<"  Pages: "<<b3.m_pages<<std::endl;
    
    auto [Name, price, author, pages] = b1;
    
    std::cout<<"\nBook 1 Details: "<<std::endl;
    std::cout<<"Name: "<<Name<<"  Price: "<<price<<"  Author: "<<author<<"  Pages: "<<pages<<std::endl;
    return 0;
}
