#include <iostream>
#include <cstdint>

class DetectedObject{
    private:
    uint32_t object_id;
    float rel_speed;  
    float distance;   

    public:

    DetectedObject(): DetectedObject(0, 0, 0){}
    
    DetectedObject(uint32_t id, float spd, float dist)
        : object_id(id), rel_speed(spd), distance(dist) {}

   
    void display() const
    {
        std::cout << "Object ID: " << object_id
             << ", RelSpeed: " << rel_speed << " km/h"
             << ", Distance: " << distance << " m" << std::endl;
    }

    
    bool isHigherRisk(const DetectedObject& other) const
    {
        return (this->distance < other.distance) &&
               (this->rel_speed > other.rel_speed);
    }

    void updateValuesByValue(DetectedObject obj)
    {
        obj.rel_speed += 2;
        obj.distance -= 5;
        std::cout << "[Inside updateValuesByValue] Modified Copy -> ";
        obj.display();
    }

    void updateValuesByReference(DetectedObject& obj)
    {
        obj.rel_speed += 2;
        obj.distance -= 5;
    }

    // Getters
    float getDistance() const { return distance; }
    float getRelSpeed() const { return rel_speed; }
    uint32_t getID() const { return object_id; }
};


void printDetectedObject(const DetectedObject& obj)
{
    obj.display();
}

void printHighestRiskObject(const DetectedObject* obj)
{
    if (obj != nullptr)
    {
        std::cout << "\nHighest Risk Object:\n";
        obj->display();
    }
    else
    {
        std::cout << "\nNo high-risk object found.\n";
    }
}

void updateObjectValuesByValueGlobal(DetectedObject obj)
{
    obj.updateValuesByValue(obj);
}

void updateObjectValuesByReferenceGlobal(DetectedObject& obj)
{
    obj.updateValuesByReference(obj);
}


void findHighestRiskObject(DetectedObject* arr, uint32_t size, const DetectedObject*& riskObj)
{
    if (arr == nullptr || size == 0)
    {
        riskObj = nullptr;
        return;
    }

    riskObj = &arr[0];
    for (uint32_t i = 1; i < size; i++)
    {
        if (arr[i].isHigherRisk(*riskObj))
        {
            riskObj = &arr[i];
        }
    }
}


int main()
{
    uint32_t size = 3;

  
    DetectedObject* objects = new DetectedObject[size] {
        DetectedObject(701, 15.0f, 55.0f),
        DetectedObject(702, 20.0f, 35.0f),
        DetectedObject(703, 10.0f, 30.0f)
    };

    
    std::cout << "Initial Detected Objects:\n";
    for (uint32_t i = 0; i < size; i++)
    {
        printDetectedObject(objects[i]);
    }

    
    std::cout << "\nUpdating Object 1 (By Value):\n";
    updateObjectValuesByValueGlobal(objects[0]);
    std::cout << "After update (Original Object remains unchanged): ";
    objects[0].display();

    
    std::cout << "\nUpdating Object 2 (By Reference):\n";
    updateObjectValuesByReferenceGlobal(objects[1]);
    std::cout << "After update (Original Object modified): ";
    objects[1].display();

    
    const DetectedObject* riskObj = nullptr;
    findHighestRiskObject(objects, size, riskObj);

    
    printHighestRiskObject(riskObj);

    
    delete[] objects;

    return 0;
}
