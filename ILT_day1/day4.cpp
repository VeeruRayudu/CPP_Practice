#include <iostream>
#include <stdexcept>

#include <iostream>


// class Demo{
//     private:
//         int value;
//         int *ptr;
//     public:
//         Demo(int v, int p){
//             value = v;
//             ptr = new int(p);
//         }
//         ~Demo() { delete ptr; }

//         // copy constructor - Shallow COPY
//         Demo ShallowCopy(Demo &other){
//             value = other.value;
//             ptr = other.ptr;    // add of 100 - ADDR   obj2ptr-->ADDR obj1ptr --> ADDR
//         }

//         // Deep Copy
//         Demo DeepCopy(){
//             Demo other(value, 0);
//             *other.ptr = *ptr;       // copy actual data
//             return other;
//         }

//         void set(int v, int p){
//             value = v;
//             *ptr = p;
//         }
//         void display(){
//             std::cout << "Value: " << value << ", Pointer: " << *ptr << std::endl;
//         }
// };

// int main(){

//     Demo obj1(10, 100);
    
//     //Demo obj2 = obj1;
//     //obj2.set(20, 200);
//     //obj2.display();
    
//     obj1.display();

//     Demo obj3 = obj1.DeepCopy();
//     obj3.set(30, 300);
//     obj3.display();
//     obj1.display();



//     return 0;
// }

// int main(){
//     try{
//         int num = 100, den = 0;
//         if(den == 0){
//             throw std::runtime_error("Division by zero");
//         }
//         std::cout<<num/den<<std::endl;
//     }
//     catch(const std::exception& msg){
//         std::cout<<msg.what()<<std::endl;
//     }
//     return 0;
// }

// class NegativeSpeedException: public std::exception{
//     public:
//     const char what() const noexcept override{
//         std::cout<<"Negative Speed Value\n";
//     }
// };

// class VehicleSpeedContorl{
//     private:
//     int speed = 0;
//     public:
//     void setSpeed(int s){
//         if(s<0){
//             throw std::invalid_argument("[Invalid Speed value: ]"+std::to_string(s)+"]");
//         } else if(s>150){
//              throw std::invalid_argument("[Speed out of range: ]"+std::to_string(s)+"]");   
//         }
//         speed = s;
//     }
//     ~VehicleSpeedContorl(){
//         std::cout<<"VehicleSpeedControl object destroyed \n";
//     }
// };

// int main(){
//     VehicleSpeedContorl car;
//     try{
//         car.setSpeed(-20);
//     }catch(const std::invalid_argument& msg){

//     }
//     return 0;
// }

 
// class VehicleSpeedControl{
//     private:
//         int speed = 0;
//     public:
      
//         void setSpeed(int spd){
//             if(spd < 0){
//                 throw std::invalid_argument("[Invalid speed value: " + std::to_string(spd) + "]");
//             }
//             else if(spd > 150){
//                 throw std::out_of_range("[Speed out of range: " + std::to_string(spd) + "]");
//             }   
//             speed = spd;
//         }
//         ~VehicleSpeedControl(){
//             std::cout << "VehicleSpeedControl object destroyed" << '\n';
//         }    
// };
// int main(){
//     VehicleSpeedControl car;
//     try{
//         car.setSpeed(20);
//     }catch(const std::invalid_argument& msg){
//         std::cout << msg.what() << '\n';
//     }
//     try{
//         car.setSpeed(-20);
//     }catch(const std::invalid_argument& msg){
//         std::cout << msg.what() << '\n';
//     }
//     try{
//         car.setSpeed(500);
//     }catch(const std::out_of_range& msg){
//         std::cout << msg.what() << '\n';
//     }   
// }

 
 
class NegativeSpeedValueException: public std::exception{
    public:
        const char* what() const noexcept override{
            return "Negative speed value is not allowed";
        }
};
class SpeedLimitException: public std::exception{
    public:
        const char* what() const noexcept override{
            return "Speed limit exceeded";
        }
};
class VehicleSpeedControl{
    private:
        int speed = 0;
    public:
      
        void setSpeed(int spd) {
            if(spd < 0){
                throw NegativeSpeedValueException();
            }
            else if(spd > 150){
                throw SpeedLimitException();
            }   
            speed = spd;
        }
        ~VehicleSpeedControl(){
            std::cout << "VehicleSpeedControl object destroyed" << '\n';
        }    
};
int main(){
    VehicleSpeedControl car;
    try{
        car.setSpeed(20);
    }catch(const NegativeSpeedValueException& msg){
        std::cout << msg.what() << '\n';
    }
    try{
        car.setSpeed(-20);
    }catch(const NegativeSpeedValueException& msg){
        std::cout << msg.what() << '\n';
    }
    try{
        car.setSpeed(500);
    }catch(const SpeedLimitException& msg){
        std::cout << msg.what() << '\n';
    }   
}
 