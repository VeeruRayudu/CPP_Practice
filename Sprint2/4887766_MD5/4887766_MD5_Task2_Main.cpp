#include "4887766_MD5_Task2_AlertManager.h"

int main(){

    AlertManager manager;

    //lambda function
    double threshold = 100.0;
    auto lambdaAlert = [=](std::string label, double value){
        if(value > threshold){
            std::cout<<"\n[Lambda = function] Label: "<<label<<" triggered at Value: "<<value<<std::endl;
        }
    };

    int alertCount = 0;
    auto lambdaAlertByRef = [&](std::string label, double value){
        if(value > threshold){
            ++alertCount;
            std::cout<<"\n[Lambda & function] Label: "<<label<<" triggered at Value: "<<value<<", "<<alertCount<<" times"<<std::endl;
        }
    };

    //handlers vector
    std::vector<std::function<void(std::string, double)>> handlers;

    //ref wrapper
    manager.m_handlers.push_back(std::ref(logAlert));

    //logger using unique_ptr
    auto logger = std::make_unique<Logger>();
    manager.m_handlers.push_back(std::bind(&Logger::record, logger.get(), std::placeholders::_1, std::placeholders::_2));

    //lambda =
    manager.m_handlers.push_back(lambdaAlert);

    //lambda &
    manager.m_handlers.push_back(lambdaAlertByRef);

    //functor
    auto functor = std::make_shared<AlertFunctor>();
    manager.m_handlers.push_back([functor](std::string label, double value){
        (*functor)(label, value);
    });
    
    manager.dispatch("Temp", 105.0);
    manager.dispatch("Pressure", 95.0);
    manager.dispatch("Voltage", 11.5);

    //replacing lambda = with mutable lambda
    if(manager.m_handlers.size() > 2){
        manager.m_handlers[2] = [count = 0](std::string label, double value) mutable{
            ++count;
            std::cout<<"\n[mutable Lambda function] Label: "<<label<<" triggered at Value: "<<value<<", "<<count<<" times"<<std::endl;
        };
    }

    //modifying handlers
    if(!manager.m_handlers.empty()){
        manager.m_handlers.erase(manager.m_handlers.begin()+3); //removing 3rd handler lambda by ref
        std::cout<<"\nRemoved Lambda by Ref handler"<<std::endl;
    }

    manager.dispatch("Speed", 120.0);
    manager.dispatch("Fuel", 15.0);

    return 0;
}