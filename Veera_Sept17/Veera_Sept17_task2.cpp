#include <iostream>
#include <limits>   
#include<cstdint>

class TrackedVehicle{
    private:
    uint32_t vehicle_id;
    float speed;
    float distance;

    static float min_recorded_distance;
    static int vehicle_count;

    public:
    TrackedVehicle(): vehicle_id(0), speed(0), distance(0){}

    // Constructor
    TrackedVehicle(uint32_t id, float spd, float dist)
        : vehicle_id(id), speed(spd), distance(dist)
    {
        vehicle_count++;

        if (dist < min_recorded_distance)
        {
            min_recorded_distance = dist;
        }
    }

    void display() const
    {
        std::cout << "Vehicle ID: " << vehicle_id
             << ", Speed: " << speed << " km/h"
             << ", Distance: " << distance << " m" << std::endl;
    }

    const TrackedVehicle* compareDistance(const TrackedVehicle& other) const
    {
        if (this->distance <= other.distance)
        {
            return this; 
        }
        else
        {
            return &other;
        }
    }

    // Getters 
    static float getMinRecordedDistance()
    {
        return min_recorded_distance;
    }

    static int getVehicleCount()
    {
        return vehicle_count;
    }

    // Getters for normal attributes
    float getDistance() const { return distance; }
    uint32_t getID() const { return vehicle_id; }
    float getSpeed() const { return speed; }
};

float TrackedVehicle::min_recorded_distance = std::numeric_limits<float>::max();
int TrackedVehicle::vehicle_count = 0;

void printTrackedVehicle(const TrackedVehicle& vehicle)
{
    vehicle.display();
}

void printLeadVehicle(const TrackedVehicle* lead)
{
    if (lead != nullptr)
    {
        std::cout << "\nLead Vehicle Identified:\n";
        lead->display();
    }
    else
    {
        std::cout << "None found\n";
    }
}

void findLeadVehicle(TrackedVehicle* arr, uint32_t size, const TrackedVehicle*& lead)
{
    if (size == 0 || arr == nullptr)
    {
        lead = nullptr;
        return;
    }

    lead = &arr[0];
    for (uint32_t i = 1; i < size; i++)
    {
        lead = lead->compareDistance(arr[i]);
    }
}

int main()
{
    uint32_t size = 4;

    TrackedVehicle* vehicles = new TrackedVehicle[size] {
        TrackedVehicle(501, 80.0f, 60.0f),
        TrackedVehicle(502, 78.0f, 45.0f),
        TrackedVehicle(503, 85.0f, 100.0f),
        TrackedVehicle(504, 76.0f, 40.0f)
    };

    const TrackedVehicle* lead = nullptr;
    findLeadVehicle(vehicles, size, lead);

    std::cout << "All Tracked Vehicles:\n";
    for (uint32_t i = 0; i < size; i++)
    {
        printTrackedVehicle(vehicles[i]);
    }

    printLeadVehicle(lead);

    std::cout << "\nMinimum Recorded Distance: " 
         << TrackedVehicle::getMinRecordedDistance() << " m\n";
    std::cout << "Total Vehicles Created: " 
         << TrackedVehicle::getVehicleCount() << std::endl;

    delete[] vehicles;

    return 0;
}


