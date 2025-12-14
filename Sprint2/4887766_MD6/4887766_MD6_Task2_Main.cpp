#include <iostream>
#include <functional>
#include <array>

int main(){
    int x = 5, y = 20;

    auto addValueCapture = [x](int y){
        return x+y;
    };

    x = 10;
    auto addReferenceCapture = [&x](int y){
        return x+y;
    };

    y=10;
    auto addDefaultCapture = [=](int z){
        return x+y+z;
    };

    auto addReferenceDefaultCapture = [&](int z){
        return x+y+z;
    };

    x = 5;
    y = 5;
    auto add = [x, &y](int a, int b){
        return a+b+x+y;
    };

    std::cout<<addValueCapture(2)<<"\n";
    std::cout<<addReferenceCapture(2)<<"\n";
    std::cout<<addDefaultCapture(2)<<"\n";
    std::cout<<addReferenceDefaultCapture(2)<<"\n";
    std::cout<<add(2, 3)<<std::endl;

}