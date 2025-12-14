#ifndef EVENT_AND_ACCROUTER_H
#define EVENT_AND_ACCROUTER_H
#include <iostream>
#include <functional>
#include <vector>
#include <memory>

struct Event{
    std::string label;
    double value;
};

class EventAndAccRouter{
    public:
    //list of handlers
    std::vector<std::function<void(const Event&)>> m_handlers;

    //append handler
    void addHandler(std::function<void(const Event&)> h);

    //remove handler
    void removeHandlerAt(size_t idx);

    //dispatch to invoke handlers
    void dispatch(const Event& e);

    //replace handler
    void replaceHandler(size_t idx, std::function<void(const Event&)> h);
};

//event logger
void logEvent(const Event&);

class Controller{
    private:
    std::string m_name;

    public:
    Controller(std::string name);
    
    //speed event handler
    void onSpeed(const Event&);
};

struct SafetyFunctor{
    int m_id;
    int m_counter = 0;

    SafetyFunctor(int id);
    void operator()(const Event&);
};

#endif