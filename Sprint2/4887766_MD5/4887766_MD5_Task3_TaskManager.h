#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H
#include <iostream>
#include <functional>
#include <vector>
#include <memory>

class TaskManager{
    public:
    //tasks to execute
    std::vector<std::function<void()>> m_tasks;

    //add new task
    void addTask(std::function<void()>);

    //run all tasks
    void runAll();
};

//logs a message
void logTask();

class Worker{
    public:
    void doWork(int id);
};

struct TaskFunctor{
    void operator()();
};

#endif