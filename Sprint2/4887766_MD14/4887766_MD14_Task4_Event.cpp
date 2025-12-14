#include "4887766_MD14_Task4_Event.h"

// event constructor initialization
explicit Event::Event(HandlerId event_id_, EventPayload payload_) : event_id(event_id_), payload(payload_) {}

HandlerId Event::id() const noexcept
{
    return event_id;
}

const EventPayload &Event::data() const noexcept
{
    return payload;
}

//---------------Dispatcher---------------------------
explicit Dispatcher::Dispatcher(HandlerId start_id_ = 1) noexcept : next_id(start_id_) {}

HandlerId Dispatcher::register_sensor_handler(std::function<void(const SensorUpdate &evt)> handler){
    HandlerId id = next_id;
    sensor_handlers[++id] = handler;
    return ++id;
}

HandlerId Dispatcher::register_command_handler(std::function<void(const Command &cmd)> handler){
    HandlerId id = next_id;
    command_handlers[++id] = handler;
    return ++id;
}

HandlerId Dispatcher::register_diag_handler(std::function<void(const Diagnostic &d)> handler){
    HandlerId id = next_id;
    diag_handlers[++id] = handler;
    return ++id;
}

bool Dispatcher::unregister_handler(HandlerId id) noexcept{
    if()
}

void Dispatcher::dispatch(const Event &evt) const noexcept{

}

void Dispatcher::dispatch_async(const Event &evt) const noexcept{

}