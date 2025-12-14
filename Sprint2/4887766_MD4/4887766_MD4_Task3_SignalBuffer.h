#ifndef SIGNALBUFFER_H
#define SIGNALBUFFER_H
#include <iostream>
#include <string>
#include <cstdint>
#include <utility>

enum class Status {VALID, WEAK, LOST};

class SignalBuffer{
    private:
    int m_id {};
    std::string m_source {};
    float m_strength {-999.0f};
    std::uint64_t m_timestamp {};
    Status m_status {Status::VALID};

    public:
    //constructor
    SignalBuffer() = default;
    SignalBuffer(int id_, std::string source_, float strength_, std::uint64_t timestamp_, Status status_);
    SignalBuffer(const SignalBuffer&) = delete;
    SignalBuffer& operator=(const SignalBuffer&) = delete;

    //move constructor
    SignalBuffer(SignalBuffer&&) noexcept;

    //move assignment
    SignalBuffer& operator=(SignalBuffer&&) noexcept;

    //update function
    void updateStrength(float s);

    //status setter
    void setStatus(Status&& ref);
    void setStatus(const Status&) = delete;

    //display
    void print() const;

    //getters
    float getStrength() const;
    Status getStatus() const;
};

//global functions
void logByRef(const SignalBuffer& b);
void logByRRef(SignalBuffer&& b);
void logByPtr(const SignalBuffer* b);

#endif