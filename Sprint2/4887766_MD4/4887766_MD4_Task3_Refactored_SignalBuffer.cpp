#ifndef SIGNALBUFFER_H
#define SIGNALBUFFER_H

#include <iostream>
#include <string>
#include <cstdint>
#include <utility>

enum class Status { VALID, WEAK, LOST };

class SignalBuffer {
private:
    int m_id{};
    std::string m_source{};
    float m_strength{-999.0f};
    std::uint64_t m_timestamp{};
    Status m_status{Status::VALID};

public:
    SignalBuffer() = default;
    SignalBuffer(int id, std::string source, float strength, std::uint64_t timestamp, Status status);
    SignalBuffer(const SignalBuffer&) = delete;
    SignalBuffer& operator=(const SignalBuffer&) = delete;

    SignalBuffer(SignalBuffer&&) noexcept;
    SignalBuffer& operator=(SignalBuffer&&) noexcept;

    void updateStrength(float strength);

    void setStatus(Status&& status);
    void setStatus(const Status&) = delete;

    void print() const;

    float getStrength() const;
    Status getStatus() const;
};

void logByRef(const SignalBuffer& buffer);
void logByRRef(SignalBuffer&& buffer);
void logByPtr(const SignalBuffer* buffer);

#endif // SIGNALBUFFER_H