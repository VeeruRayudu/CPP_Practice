#include <iostream>

class MyClass{
    private:
    int myIntVar{};           //value initialization myIntVar = 0
    double myDoubleVar{0};       //in class member initialization
    std::string myStringVar{};   //as per string class default value mystringvar = ""
    int* myIntPtr{nullptr};

    public:
    MyClass() : myIntVar(0), myDoubleVar(0.0), myStringVar(""), myIntPtr(nullptr) {}

    MyClass(int i, double d, std::string s, int* p) : myIntVar(i), myDoubleVar(d), myStringVar(s), myIntPtr(p) {} //member list initialization

    //Move constructor
    MyClass(MyClass&& other) : myIntVar(other.myIntVar), myDoubleVar(other.myDoubleVar), myStringVar(std::move(other.myStringVar)), myIntPtr(other.myIntPtr) { other.myIntPtr = nullptr; }

    MyClass(MyClass& other) = delete;

    ~MyClass() {}
    void display() const {
        std::cout<<"Integer Var: "<<myIntVar<<std::endl;
        std::cout<<"Double Var: "<<myDoubleVar<<std::endl;
        std::cout<<"String Var: "<<myStringVar<<std::endl;
        if(myIntPtr != nullptr){
        std::cout<<"Pointer Var: "<<*myIntPtr<<std::endl;
        }else{
            std::cout<<"Pointer Var: nullptr"<<std::endl;
        }
    }


};

int main(){
    MyClass obj1(10, 20.5, "Hello", nullptr);
    obj1.display();
    std::cout<<"\n------------------------------------------------\n";
    MyClass obj2 = std::move(obj1);
    obj2.display();
    std::cout<<"\n------------------------------------------------\n";
    obj1.display();
}



// #include <array>
// #include <algorithm>

// int main(){
//     // ------------------------------------
//     auto lambda1 = [](){
//         std::cout << "Hello World!\n";
//     };
//     lambda1();  // Hello World!


//     // ------------------------------------
//     auto lambda2 = [](int a, int b) -> int{
//         return a + b;
//     };
//     std::cout << lambda2(10, 20) << std::endl;  // 30

//     // ------------------------------------ // capture by value
//     int var = 10;
//     auto lambda3 = [var](int par1)->int{
//         return par1 + var;
//     };
//     var = 20;
//     std::cout << lambda3(20) << std::endl;  // 30 = 20 + 10

//     // ------------------------------------ // capture by reference
//     int var1 = 10;
//     auto lambda4 = [var, &var1](int par1)->int{
//         return par1 + var1 + var;
//     };
//     var1 = 20;
//     std::cout << lambda4(20) << std::endl;  // 60 = 20 + 20 + 20

//     // ------------------------------------ // capture all by value
//     auto lambda5 = [=](int par1)->int{
//         return par1 + var + var1;
//     };
//     //var = 25;
//     //var1 = 35;
//     std::cout << lambda5(20) << std::endl;  // 60 = 20 + 20 + 20

//     // ------------------------------------ // capture all by reference
//     auto lambda6 = [&](int par1)->int{
//         return par1 + var + var1;
//     };
//     var = 25;
//     var1 = 35;
//     std::cout << lambda6(20) << std::endl;  // 80 = 20 + 25 + 35

//     // -----------------------------------------
    
//     std::array<int,7> number {1,2,3,4,5,6,7};
//     for(auto it = number.begin(); it != number.end(); ++it){
//         std::cout << *it << std::endl;
//     }

//     // range based for loop
//     for(int& it: number){
//         std::cout << it << ' ';
//     }
//     std::cout << std::endl;
//     std::for_each(number.begin(), number.end(),[](int par){std::cout << par << ' ';});
        

//     return 0;
// }
