#ifndef TRIP_H
#define TRIP_H
#include <iostream>
#include <string>

enum RIDE { REGULAR, COMFORT };

class Trip{
    private:
    std::string m_tripID;
    int m_tripDistance;
    int m_tripRating;
    RIDE m_tripVehicleType;

    public:
    //constructor
    Trip(std::string tripID_ = "", int tripDistance_ = 0, int tripRating_ = 0, RIDE tripVehicleType_ = RIDE::REGULAR);

    //virtual destructor
    virtual ~Trip();

    //getters
    std::string getTripID() const { return m_tripID; }
    int getTripDistance() const { return m_tripDistance; }
    int getTripRating() const { return m_tripRating; }
    RIDE getTripVehicleType() const { return m_tripVehicleType; }

    //setters
    void setTripID(std::string id) { m_tripID = id; }
    void setTripDistance(int dist) { m_tripDistance = dist; }
    void setTripRating(int rating) { m_tripRating = rating; }
    void setTripVehicleType(RIDE type) { m_tripVehicleType = type; }

    std::string typeToString(RIDE r);

    //<< overload
    friend std::ostream& operator<<(std::ostream& os, const Trip& trip);

    virtual float calculateFare() = 0;
};

#endif