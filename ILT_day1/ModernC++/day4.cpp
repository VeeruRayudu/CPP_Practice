#include <iostream>
#include <functional>
#include <algorithm>

// int add(int n1, int n2){
//     return n1+n2;
// }

// int subtract(int n1, int n2){
//     return n1-n2;
// }

// int multiply(int n1, int n2){
//     return n1*n2;
// }

// class Calculator{
//     public:
//     int add(int n1, int n2){
//         return n1 + n2;
//     }
//     static int staticAdd(int n1, int n2){
//         return n1 + n2;
//     }
// };


// // void executeAndDisplay(int n1, int n2, int (*operation)(int, int)){
// //     std::cout<<"ExecuteAndDisplay: "<<operation(n1,n2)<<std::endl;
// // }

// using mathOperation = int(*)(int, int);
// void executeAndDisplay(int n1, int n2, mathOperation operation){
//     std::cout<<"ExecuteAndDisplay: "<<operation(n1,n2)<<std::endl;
// }

// using mathOperate = std::function<int(int, int)>;
// void executeAndDisplayWithStd(int n1, int n2, mathOperate operation){
//     std::cout<<"ExecuteAndDisplayWithStd: "<<operation(n1,n2)<<std::endl;
// }

// int main(){
//     std::cout<<"Normal Call: "<<add(10,20)<<std::endl;
//     std::cout<<"Normal Call: "<<subtract(10,20)<<std::endl;
//     std::cout<<"Normal Call: "<<multiply(10,20)<<std::endl;

//     int (*operation)(int, int);
//     operation = add;
//     std::cout<<"Function pointer"<<operation(10,20)<<std::endl;

//     operation = subtract;
//     std::cout<<"Function pointer"<<operation(10,20)<<std::endl;

//     operation = multiply;
//     std::cout<<"Function pointer"<<operation(10,20)<<std::endl;

//     auto lambda = [](int n1, int n2) { return n1+n2; };
//     operation = lambda;
//     std::cout<<"Function pointer"<<operation(10,20)<<std::endl;

//     int bias = 5;
//     auto lambdaCapture = [bias](int n1, int n2) { return n1 + n2 + bias; };
//     // operation = lambdaCapture; //Function pointer cannot work with lambda capture

//     Calculator calc;
//     // operation = calc.add;  //Function pointer cannot work with class member functions

//     operation = Calculator::staticAdd; //static doesn't need object

//     executeAndDisplay(10,20,add);
//     executeAndDisplay(10,20,subtract);
//     executeAndDisplay(10,20,multiply);
//     executeAndDisplay(10,20,lambda);
//     executeAndDisplay(10,20,Calculator::staticAdd);

//     std::function<int(int,int)> op;
//     op = add;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     op = subtract;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     op = multiply;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     op = lambda;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     op = lambdaCapture;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     // op = Calculator::add;
//     mathOperate opbind = std::bind(&Calculator::add,&calc,std::placeholders::_1,std::placeholders::_2);
//     std::cout << "std::function" << opbind(10, 20) << std::endl;

//     op = Calculator::staticAdd;
//     std::cout<<"std::Function pointer "<<op(10,20)<<std::endl;

//     executeAndDisplayWithStd(10,20,add);
//     executeAndDisplayWithStd(10,20,subtract);
//     executeAndDisplayWithStd(10,20,multiply);
//     executeAndDisplayWithStd(10,20,lambda);
//     executeAndDisplayWithStd(10,20,lambdaCapture);
//     executeAndDisplayWithStd(10,20,Calculator::staticAdd);
// }



// #include <functional>
// int add(int num1, int num2){
//     return num1 + num2;
// }

// int subtract(int num1, int num2){
//     return num1 - num2;
// }

// int multiply(int num1, int num2){
//     return num1 * num2;
// }

// class Calculator{
//     public:
//         int addition(int num1, int num2){
//             return num1 + num2;
//         }

//         static int staticAdddition(int num1, int num2){
//             return num1 + num2;
//         }
// };

// using mathOperation = int(*)(int, int);

// void executeAndDisplay(const int num1,const int num2,const mathOperation& operation){
//     std::cout << "executeAndDisplay " << operation(num1, num2) << std::endl;
// }

// using mathOperationStdFunction = std::function<int(int,int)>;

// void executewithStdFunction(const int num1,const int num2,const mathOperationStdFunction& operation){
//     std::cout << "executewithStdFunction " << operation(num1, num2) << std::endl;
// }

// int main(){
//     std::cout << "Normal call " << add(10, 20) << std::endl;
//     std::cout << "Normal call " << subtract(10, 20) << std::endl;

//     // declaration of function pointer thaty takes 2 int arduments and return int
//     int (*operation)(int, int);

//     operation = add;
//     std::cout << "Function pointer" << operation(10, 20) << std::endl;

//     operation = subtract;
//     std::cout << "Function pointer" << operation(10, 20) << std::endl;

//     auto lambda = [](int num1, int num2) { return num1 * num2; };
//     operation = lambda;
//     std::cout << "Function pointer" << operation(10, 20) << std::endl;

//     int bias = 5;
//     auto lambdaCapture = [&bias](int num1, int num2) { return num1 * num2 + bias; };
//     // operation = lambdaCapture;   // function pointers can not work with lambda capture 
    
//     Calculator calc;
//     // operation = calc.addition;  // NOT Allowed, 

//     operation = Calculator::staticAdddition;
//     std::cout << "Function pointer static function" << operation(10, 20) << std::endl;

//     executeAndDisplay(10, 20, add);
//     executeAndDisplay(10, 20, subtract);
//     executeAndDisplay(10, 20, lambda);
//     executeAndDisplay(10, 20, Calculator::staticAdddition);
//     std::cout << "-----------------------------------\n";
//     std::function<int(int,int)> op;
//     op = add;
//     std::cout << "std::function " << op(10, 20) << std::endl;

//     op = subtract;
//     std::cout << "std::function" << op(10, 20) << std::endl;

//     op = lambda;
//     std::cout << "std::function" << op(10, 20) << std::endl;

//     op = lambdaCapture;
//     std::cout << "std::function" << op(10, 20) << std::endl;

    // mathOperationStdFunction opbind = std::bind(&Calculator::addition,&calc,std::placeholders::_1,std::placeholders::_2);
    // std::cout << "std::function" << opbind(10, 20) << std::endl;

//     op = Calculator::staticAdddition;
//     std::cout << "std::function" << op(10, 20) << std::endl;
    
//     std::cout << "-----------------------------------\n";
//     executewithStdFunction(10, 20, add);
//     executewithStdFunction(10, 20, subtract);
//     executewithStdFunction(10, 20, lambda);
//     executewithStdFunction(10, 20, lambdaCapture);
//     executewithStdFunction(10, 20, opbind);
//     executewithStdFunction(10, 20, Calculator::staticAdddition);
// }


#include <memory>

class Demo{
    public:
    Demo() {std::cout << "Demo constructor called" << std::endl;}
    ~Demo(){std::cout << "Demo destructor called" << std::endl;}
    void display(){std::cout << "Hello\n"; }
};

int main(){
    Demo* demo1 = new Demo;
    demo1->display();
    delete demo1;

    // unique pointer
    std::unique_ptr<Demo> demo2 = std::make_unique<Demo>();
    demo2->display();

    // std::unique_ptr<Demo> demo3 = demo2; // can not copy
    std::unique_ptr<Demo> demo3 = std::move(demo2); // ownership transfer allowed

    // shared pointer
    std::shared_ptr<Demo> demo4 = std::make_shared<Demo>();
    demo4->display();

    std::shared_ptr<Demo> demo5 = demo4;    // copy is allowed, shared ownership
    demo5->display();
    std::cout << "count " << demo4.use_count() << '\n';

    // weak pointer
    std::weak_ptr<Demo> demo6weak = demo5;

    auto temp = demo6weak.lock();
    temp->display();
}