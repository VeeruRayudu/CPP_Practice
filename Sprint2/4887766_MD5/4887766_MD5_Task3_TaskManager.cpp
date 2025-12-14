#include "4887766_MD5_Task3_TaskManager.h"

// add new task
void TaskManager::addTask(std::function<void()> task){
    m_tasks.push_back(task);
}

// run all tasks
void TaskManager::runAll(){
    for(auto& task : m_tasks){
        task();
    }
}

// logs a message -- free function
void logTask(){
    std::cout<<"\nLogging task executed"<<std::endl;
}

//Worker member function
void Worker::doWork(int id){
    std::cout<<"\nWorker 42 executed"<<std::endl;
}

//functor
void TaskFunctor::operator()(){
    std::cout<<"\nFunctor executed"<<std::endl;
}
