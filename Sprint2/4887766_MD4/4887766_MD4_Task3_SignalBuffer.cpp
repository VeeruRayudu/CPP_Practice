#include "4887766_MD4_Task3_SignalBuffer.h"

//constructor initialization
SignalBuffer::SignalBuffer(int id_, std::string source_, float strength_, std::uint64_t timestamp_, Status status_) : m_id(id_), m_source(source_), m_strength(strength_), m_timestamp(timestamp_), m_status(status_) {}

// move constructor
SignalBuffer::SignalBuffer(SignalBuffer&& buffer) noexcept : m_id(buffer.m_id), m_source(std::move(buffer.m_source)), m_strength(buffer.m_strength), m_timestamp(buffer.m_timestamp), m_status(buffer.m_status) {
    buffer.m_id = -1;
    buffer.m_strength = -999.0f;
    buffer.m_timestamp = 0;
    buffer.m_status = Status::LOST;
    buffer.m_source = "Moved-from";
}

// move assignment
SignalBuffer& SignalBuffer::operator=(SignalBuffer&& buffer) noexcept{
    if(this != &buffer){
        m_id = buffer.m_id;
        m_source = buffer.m_source;
        m_strength = buffer.m_strength;
        m_timestamp = buffer.m_timestamp;
        m_status = buffer.m_status;

        //marking moved
        buffer.m_id = -1;
        buffer.m_strength = -999.0f;
        buffer.m_timestamp = 0;
        buffer.m_status = Status::LOST;
        buffer.m_source = "Moved-from";
    }
    return *this;
}

// update function
void SignalBuffer::updateStrength(float s){
    m_strength = s;
}

// status setter
void SignalBuffer::setStatus(Status &&ref){
    m_status = std::move(ref);
}

static std::string toString(Status s){
    switch (s)
    {
    case Status::LOST : return "LOST";
    case Status::VALID : return "VALID";
    case Status::WEAK : return "WEAK";
    default: return "UNKNOWN";
}
}

// display
void SignalBuffer::print() const{
    std::cout<<"\nBuffer ID: "<<m_id<<std::endl;
    std::cout<<"Signal Source: "<<m_source<<std::endl;
    std::cout<<"Strength: "<<m_strength<<std::endl;
    std::cout<<"Timestamp: "<<m_timestamp<<std::endl;
    std::cout<<"Status: "<<toString(m_status)<<std::endl;
}

// getters
float SignalBuffer::getStrength() const{
    return m_strength;
}
Status SignalBuffer::getStatus() const{
    return m_status;
}

//logger functions
void logByRef(const SignalBuffer& b){
    std::cout<<"\nCall By Reference:\n"<<std::endl;
    b.print();
}

void logByRRef(SignalBuffer&& b){
    std::cout<<"\nCall By Rvalue Reference:\n"<<std::endl;
    b.print();
}

void logByPtr(const SignalBuffer* b){
    std::cout<<"\nCall By Pointer:\n"<<std::endl;
    b->print();
}