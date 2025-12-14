#ifndef EVENT_H
#define EVENT_H
#include <iostream>
#include <cstdint>
#include <variant>
#include <vector>
#include <mutex>
#include <unordered_map>
#include <functional>

using Timestamp = std::int64_t;
using HandlerId = std::uint64_t;
using EventPayload = std::variant<SensorUpdate, Command, Diagnostic>;

struct SensorUpdate{
    std::string sensor;
    double value;
    Timestamp ts;
};

struct Command{
    std::string name;
    std::vector<std::string> args;
};

struct Diagnostic{
    int code;
    std::string message;
};

class Event{
    private:
    HandlerId event_id;
    EventPayload payload;

    public:
    Event() = delete;

    explicit Event(HandlerId event_id_, EventPayload payload_);

    //defaulted move and copy operations
    Event(const Event&) = default;
    Event& operator=(const Event&) = default;
    Event(Event&&) = default;
    Event& operator=(Event&&) = default;

    HandlerId id() const noexcept;
    const EventPayload& data() const noexcept;
};

class Dispatcher{
    private:
    mutable std::mutex mtx;
    HandlerId next_id;
    std::unordered_map<HandlerId, std::function<void(const SensorUpdate&)>> sensor_handlers;
    std::unordered_map<HandlerId, std::function<void(const Command&)>> command_handlers;
    std::unordered_map<HandlerId, std::function<void(const Diagnostic&)>> diag_handlers;

    public:
    Dispatcher() = delete;

    explicit Dispatcher(HandlerId start_id_ = 1) noexcept;

    Dispatcher(const Dispatcher&) = default;
    Dispatcher& operator=(const Dispatcher&) = default;
    Dispatcher(Dispatcher&&) = default;
    Dispatcher& operator=(Dispatcher&&) = default;

    HandlerId register_sensor_handler(std::function<void(const SensorUpdate& evt)> handler);

    HandlerId register_command_handler(std::function<void(const Command& cmd)> handler);

    HandlerId register_diag_handler(std::function<void(const Diagnostic& d)> handler);

    bool unregister_handler(HandlerId id) noexcept;

    void dispatch(const Event& evt) const noexcept;

    void dispatch_async(const Event& evt) const noexcept;
};

std::string to_lower_copy(const std::string& s) noexcept;

std::string payload_type_name(const EventPayload& p) noexcept;

#endif