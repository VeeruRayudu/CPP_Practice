#include<iostream>
#include<string>

class ObjectDistance{
    private:
    float radar_distance;
    float camera_distance;

    public:
    ObjectDistance(float _radar_distance, float _camera_distance): radar_distance(_radar_distance), camera_distance(_camera_distance){}

    //getters
    float getRadarDistance() const {return radar_distance;}
    float getCameraDistance() const {return camera_distance;}

    void adjustDistanceByValue(ObjectDistance obj){
        //calibration
        obj.radar_distance+=5.0;
        obj.camera_distance+=5.0;

        std::cout<<"\nInside adjustDistanceByValue func\n"<<"Radar"<<obj.radar_distance<<" Camera: "<<obj.camera_distance<<std::endl;
    }

    void adjustDistanceByReference(ObjectDistance &obj){
        obj.radar_distance+=5.0;
        obj.camera_distance+=5.0;
    }
};

void printObjectDistance(const ObjectDistance &obj){
    std::cout<<"Radar distance: "<<obj.getRadarDistance()<<" Camera distance: "<<obj.getCameraDistance()<<std::endl;
}
ObjectDistance* createObjectDistanceOnHeap(float radar, float camera){
    return new ObjectDistance(radar, camera);
}

int main(){
    ObjectDistance *object = createObjectDistanceOnHeap(35.5F, 34.8F);

    std::cout<<"\n------Inital distance-------\n";
    printObjectDistance(*object);

    std::cout<<"\n----Adjusting By Value----"<<std::endl;
    object->adjustDistanceByValue(*object);
    std::cout<<"\n----After adjusting by value------\n"<<std::endl;
    printObjectDistance(*object);

    std::cout<<"\n----After Adjusting By Reference----\n";
    object->adjustDistanceByReference(*object);
    printObjectDistance(*object);

    delete object;

    return 0;
}