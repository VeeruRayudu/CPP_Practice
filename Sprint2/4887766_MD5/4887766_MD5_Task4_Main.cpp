#include "4887766_MD5_Task4_EventAndAccRouter.h"

int main(){
    EventAndAccRouter router;

    //free function
    router.addHandler(std::ref(logEvent));

    //lambda cap by value
    double threshold = 100.0;
    router.addHandler([threshold](const Event& e){
        if(e.value > threshold){
            std::cout<<"\n[Lambda By value] Label: "<<e.label<<", Value: "<<e.value<<std::endl;
        }
    });

    //lambda cap by ref
    int counter = 0;
    router.addHandler([&counter](const Event& e){
        ++counter;
        std::cout<<"\n[Lambda By Ref] Label: "<<e.label<<", Value: "<<e.value<<", triggered "<<counter<<" times"<<std::endl;
    });

    //Controller handler using unique_ptr
    std::unique_ptr<Controller> ctrl = std::make_unique<Controller>("ACC_CTRL");
    router.addHandler(std::bind(&Controller::onSpeed, ctrl.get(), std::placeholders::_1));

    //functor using shared_ptr
    std::shared_ptr<SafetyFunctor> sf = std::make_shared<SafetyFunctor>(7);
    router.addHandler(std::bind(&SafetyFunctor::operator(), sf.get(), std::placeholders::_1));

    //mutable lambda
    router.addHandler([limit = threshold*1.1, calls = 0](const Event& e) mutable{
         if(e.value > limit){
            ++calls;
            std::cout<<"\n[Mutable Lambda] Label: "<<e.label<<", Value: "<<e.value<<", triggered "<<calls<<" times"<<std::endl;
         }
    });

    //dispatch
    std::cout << "\n--- Original order ---";
    Event e {"speed", 20.0};
    router.dispatch(e);

    //replacing lambda by value handler
    threshold = 10.0;
    std::cout<<"\nReplacing Lambda by Value handler"<<std::endl;
    router.replaceHandler(1, [threshold](const Event& e){
        if(e.value > threshold){
        std::cout<<"\n[Replaced Lambda] Label: "<<e.label<<", Value: "<<e.value<<std::endl;
        }
    });

    //removing functor handler
    router.removeHandlerAt(4);

    //swapping handlers
    std::swap(router.m_handlers[0], router.m_handlers[3]);

    //calling dispatch
    std::cout << "\n--- After swap ---";
    Event e1 {"LeadDist", 25.0};
    router.dispatch(e1);

    //invocation counters
    std::shared_ptr<int> counter0 = std::make_shared<int>(0);
    router.addHandler([counter0](const Event& e){
        ++(*counter0);
        std::cout << "[Invocation counter 0] count=" << *counter0 << " (event " << e.label << ")\n";
    });

     std::vector<Event> events = {
        {"Speed", 120.0},   
        {"Lead Dist", 25.0},
        {"Speed", 75.0},    
        {"Speed", 95.0},     
        {"Brake", 1.0}      
    };

    router.dispatch(events[2]);
    router.dispatch(events[3]);
    router.dispatch(events[4]);

    return 0;
}