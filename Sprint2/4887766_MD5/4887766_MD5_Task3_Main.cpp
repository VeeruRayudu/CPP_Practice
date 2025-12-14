#include "4887766_MD5_Task3_TaskManager.h"

int main(){
    //task manager object creation
    TaskManager manager;

    //task using lambda by ref
    int counter = 0;
    manager.addTask([&](){
        ++counter;
        std::cout<<"\nLambda task executed with counter = "<<counter<<std::endl;
    });

    //free function wrapped with ref
    manager.addTask(std::ref(logTask));

    //bound member function
    auto worker = std::make_unique<Worker>();
    manager.addTask(std::bind(&Worker::doWork, worker.get(), 42));

    //functor
    auto functor = std::make_shared<TaskFunctor>();
    manager.addTask([functor](){
        (*functor)();
    });

    //adding mutable lambda
    manager.addTask([count = 0]() mutable{
        ++count;
        std::cout<<"\nMutable Lambda task executed with count = "<<count<<std::endl;
    });

    manager.runAll();

    std::cout<<"\nRemoving Lambda by Reference task --"<<std::endl;
    if(!manager.m_tasks.empty()){
        manager.m_tasks.erase(manager.m_tasks.begin());  //removed lambda task

    }
    std::cout<<"\nRemoved Lambda task --"<<std::endl;

    manager.runAll();

    return 0;
}