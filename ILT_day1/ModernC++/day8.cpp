#include <iostream>
#include <variant>

// struct visitor{
//     void operator()(int var){std::cout << "accessing int value " << var << '\n';}
//     void operator()(double var){std::cout << "accessing char value " << var << '\n';}
//     void operator()(char var){std::cout << "accessing double value " << var << '\n';}
// };

// std::variant<int, std::string> myFunction(int arg){
//     if(arg>0){
//         return 10;
//     }else{
//         return std::string("OK");
//     }
// }

// int main(){
//     std::variant<int, char, double> myVariant;

//     myVariant = 10;
//     std::cout<<std::get<int>(myVariant)<<std::endl;
    
//     myVariant = 'A';
//     std::cout<<std::get<char>(myVariant)<<std::endl;

//     myVariant = 3.20;
//     std::cout<<std::get<double>(myVariant)<<std::endl;

//     try{
//         std::cout<<std::get<int>(myVariant)<<std::endl;
//     }catch(const std::bad_variant_access& e){
//         std::cout<<"Error: Invalid type"<<e.what()<<std::endl;
//     }

//     std::visit(visitor{}, myVariant);

//     myVariant = 'k';
//     std::visit(visitor{}, myVariant);

//     std::visit([](auto&& var){std::cout << "accessing value "<< var <<std::endl;}, myVariant);

//     auto var = myFunction(-1);
//     std::visit([](auto&& var){std::cout<<"Value is "<<var<<std::endl;}, var);

//     return 0;
// }

class Car{
    public:
    void display(){
        std::cout << "Car is running" << std::endl;
    }
    void drive(){
        std::cout << "Car is driving" << std::endl;
    }
};

class Truck{
    public:
    void display(){
        std::cout << "Truck is running" << std::endl;
    }
    void haul(){
        std::cout << "Truck is hauling" << std::endl;
    }
};

class Bike{
    public:
    void display(){
        std::cout<< "Bike is running" << std::endl;
    }
    void ride(){
        std::cout<< "Bike is riding" << std::endl;
    }
};

//void operation(std::variant<Car, Truck, Bike>& vehicle)
void operation(std::variant<Car, Truck, Bike> vehicle){
    std::visit([](auto&& var){var.display();}, vehicle);

    if(std::holds_alternative<Car>(vehicle)){
        std::get<Car>(vehicle).drive();
    }

    if(std::holds_alternative<Truck>(vehicle)){
        std::get<Truck>(vehicle).haul();
    }

    if(std::holds_alternative<Bike>(vehicle)){
        std::get<Bike>(vehicle).ride();
    }
}

int main(){
    Car car;
    Truck truck;
    Bike bike;

    // std::variant<Car, Truck, Bike> vehicle;
    // vehicle = car;
    // operation(car);
    // vehicle = truck;
    // operation(truck);
    // vehicle = bike;
    // operation(bike);

    operation(car);
    operation(truck);
    operation(bike);

    return 0;
}

/** 
std::optional
g++ -std=c++17 day8 
*/