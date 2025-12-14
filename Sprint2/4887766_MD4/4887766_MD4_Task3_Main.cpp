#include "4887766_MD4_Task3_SignalBuffer.h"

int main(){
    SignalBuffer buffer[5] {
        {501, "Alpha", -65.0, 1620000000, Status::VALID},
        {502, "Beta", -85.0, 1620000100, Status::WEAK},
        {503, "Gamma", -120.0, 1620000200, Status::LOST},
        {504, "Delta", -70.0, 1620000300, Status::VALID},
        {505, "Epsilon", -95.0, 1620000400, Status::WEAK}
    };

    //default
    SignalBuffer sb1;
    //member-list
    SignalBuffer sb2(502, "Beta", -85.0, 1620000100, Status::WEAK);
    //uniform initialization
    SignalBuffer sb3{503, "Gamma", -120.0, 1620000200, Status::LOST};
    //value initialization
    SignalBuffer sb4{};
    //in-class initialization

    std::cout<<"\n-----------------INITIAL DETAILS-----------------\n";
    std::cout<<"Default:"<<std::endl;
    sb1.print();
    std::cout<<"\nMember-list:"<<std::endl;
    sb2.print();
    std::cout<<"\nuniform initialization:"<<std::endl;
    sb3.print();
    std::cout<<"\nvalue initialization:"<<std::endl;
    sb4.print();

    //updating stregth
    sb1.updateStrength(-65.0);

    //setting status
    sb4.setStatus(Status::VALID);

    std::cout<<"\n-----------------AFTER UPDATE-----------------\n";
    sb1.print();
    sb4.print();

    //copy operations:
    // sb1 = sb2;
    // SignalBuffer sb6 = sb2;

    //logging
    std::cout<<"\n-----------------LOGGER-----------------\n";
    logByRef(sb2);
    logByRRef(std::move(sb3));
    logByPtr(&buffer[4]);

    float threshold = -90.0f;
    //capture by value
    auto lambda1 = [threshold]() { return threshold; };
    //capture by reference
    auto lambda2 = [&threshold]() { return threshold; };
    //capture all by value
    auto lambda3 = [=]() { return threshold; };
    //capture all by reference
    auto lambda4 = [&]() { return threshold+5.0f; };
    //init capture
    auto lambda5 = [limit = threshold+5.0f]() { return limit; };
    //mutable lambda
    auto lambda6 = [threshold]() mutable { 
        threshold -= 0.1f;
        return threshold;
    };

    std::cout<<"\n-----------------LAMBDA FUNCTIONS-----------------";
    std::cout<<"\ncapture by value: "<<lambda1()<<std::endl;
    std::cout<<"\ncapture by reference: "<<lambda2()<<std::endl;
    std::cout<<"\ncapture all by value: "<<lambda3()<<std::endl;
    std::cout<<"\ncapture all by reference: "<<lambda4()<<std::endl;
    std::cout<<"\ninit capture: "<<lambda5()<<std::endl;
    std::cout<<"\nmutable lambda: "<<lambda6()<<std::endl;

    //filter via lambda
    auto filter = [](const SignalBuffer& b){
        return (b.getStrength() < -90.0f || b.getStatus() == Status::LOST);
    };

    //storing filtered results
    SignalBuffer weakSignals[5];
    int count = 0;
    for(auto& b : buffer){
        if(filter(b)){
            weakSignals[count++] = std::move(b);
        }
    }
    //display weak signals
    std::cout<<"\n-----------------WEAK SIGNALS-----------------\n";
    for(int i=0; i<count; i++){
        weakSignals[i].print();
    }
}
