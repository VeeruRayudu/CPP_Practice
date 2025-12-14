#include <iostream>

// class Demo{
//     private:
//         int num;
//         double val;
//         std::string data;
    
//     public:
//         //Demo() = default;
//         //constructor delegation
//         Demo() : Demo(0,0.0,"") {};
//         Demo(std::string str): Demo(0,0.0,str){};
//         Demo(int n, double v, std::string d): num(n), val(v), data(d) {};
//         void setData(int n, double v, std::string d) = delete;
//         void printData(){
//             std::cout<<"Number: "<<num<<"\n"
//                      <<"Value: "<<val<<"\n"
//                      <<"Data: "<<data<<"\n"; 
//         }
//         Demo(const Demo& other) = delete;
//         Demo& operator=(const Demo& other) = delete;
//         ~Demo() = default;
//         void *operator new(size_t) = delete;
//         void operator delete(void*) = delete;
// };

// class 

// int main(){
//     Demo obj1;
//     Demo obj2(10, 20.5, "hi");
//     // Demo obj3(obj1);
//     // Demo obj4 = obj2;
//     obj1.printData();
//     obj2.printData();
//     // Demo* ptr = new(sizeof(Demo));
//     Demo obj3("Hello");
//     obj3.printData();
// }



//--------------------------------------------------------------------------------------------------------------------------------
// #include <iostream>


// class DemoClass{
//     private:
//         int number;
//         double value;
//         std::string data;
//     public:
//         // DemoClass():number(0), value(0.0), data(""){}
//         DemoClass():DemoClass(0,0.0,""){};  // constructor Delegation

//         DemoClass(std::string str):DemoClass(0, 0.0, str){}

//         DemoClass(int num, double val, std::string dt):number(num), value(val), data(dt){}
        
//         virtual void printData() const {
//             std::cout << "Number: " << number << std::endl;
//             std::cout << "Value: " << value << std::endl;
//             std::cout << "Data: " << data << std::endl;
//         }

//         void setData(int num, double val, std::string dt) = delete;

//         //DemoClass(const DemoClass& other) : number(other.number), value(other.value), data(other.data) {}
//         DemoClass(const DemoClass& other) = delete;
//         DemoClass& operator=(const DemoClass& other) = delete;
//         ~DemoClass() = default;

//         void *operator new(size_t) = delete;
//         void operator delete(void*) = delete;
// };

// class DerivedClass:public DemoClass{
//     public:
//         void printData() const override final{
//             std::cout << "in derived class" << std::endl;
//         }

// };


// class DerivedClass2:public DerivedClass{
//     public:
//         // void printData() const {
//         //     std::cout << "in derived class" << std::endl;
//         // }

// };


// using DemoClassPtr = DemoClass*;

// using myString = std::string;

// int main(){
//     DemoClass obj1(10,20.5,"Hello");
//     DemoClass obj2;
//     obj1.printData();

//     // DemoClass obj3(obj1);
//     // DemoClass obj4 = obj1;
//     // obj2.printData();

//     // DemoClass* ptr = new(sizeof(DemoClass));

//     DemoClass obj5("Hello");

//     DemoClass* objArray[10];
//     DemoClassPtr objArray[10];

//     myString s1;

//     int var = 10;
//     std::cout << var << std::endl;

//     auto var2 = 10;
//     std::cout << var2 << std::endl;

//     auto name = "Parag";

//     return 0;
// }

//----------------------------------------------------------------------------------------------

enum Color{
    RED,
    GREEN,
    YELLOW
};

enum class TrafficLight{
    RED,
    GREEN,
    YELLOW
};

void displayColor(Color clr){
    switch (clr) {
    case RED:
        std::cout << "Color is RED" << std::endl;
        break;
    case GREEN:
        std::cout << "Color is GREEN" << std::endl;
        break;
    case YELLOW:
        std::cout << "Color is YELLOW" << std::endl;
        break;
    default:
        std::cout << "Invalid color" << std::endl;
        break;
    }
}

void displayTrafficLight(TrafficLight light){
    switch (light) {
    case TrafficLight::RED:
        std::cout << "TrafficLight is RED" << std::endl;
        break;
    case TrafficLight::GREEN:
        std::cout << "TrafficLight is GREEN" << std::endl;
        break;
    case TrafficLight::YELLOW:
        std::cout << "TrafficLight is YELLOW" << std::endl;
        break;
    default:
        std::cout << "Invalid TrafficLight" << std::endl;
        break;
    }
}


int main(){
    Color color = RED;
    std::cout << "color is " << color << std::endl;

    TrafficLight light = TrafficLight::RED;
    std::cout << "TrafficLight is " << static_cast<int>(light) << std::endl;
}