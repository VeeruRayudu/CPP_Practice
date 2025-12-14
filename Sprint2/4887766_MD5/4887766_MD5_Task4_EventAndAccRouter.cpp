#include "4887766_MD5_Task4_EventAndAccRouter.h"

// append handler
void EventAndAccRouter::addHandler(std::function<void(const Event &)> h){
    m_handlers.push_back(h);
}

// remove handler
void EventAndAccRouter::removeHandlerAt(size_t idx){
    if(!m_handlers.empty()){
        m_handlers.erase(m_handlers.begin()+idx);
    }
}

// dispatch to invoke handlers
void EventAndAccRouter::dispatch(const Event &e){
    for(auto& handler : m_handlers){
        handler(e);
    }
}

// replace handler
void EventAndAccRouter::replaceHandler(size_t idx, std::function<void(const Event &)> h){
    if(m_handlers.size() > idx){
        m_handlers[idx] = std::move(h);
    }
}

// event logger
void logEvent(const Event& e){
    std::cout<<"\n[Free function logEvent] Label: "<<e.label<<", Value: "<<e.value<<std::endl;
}

Controller::Controller(std::string name){
    m_name = name;
}

// speed event handler
void Controller::onSpeed(const Event& e){
    std::cout<<"\n[Bound function onSpeed] Label: "<<e.label<<", Value: "<<e.value<<std::endl;
}

SafetyFunctor::SafetyFunctor(int id){
    m_id = id;
}

void SafetyFunctor::operator()(const Event& e){
    ++m_counter;
    std::cout<<"\n[Functor function] Label: "<<e.label<<", Value: "<<e.value<<", triggered "<<m_counter<<" times"<<std::endl;
}

