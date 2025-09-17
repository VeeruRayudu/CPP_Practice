#include<iostream>

class RadarSignal {
    private:
    int numChannels;
    float *signalStrength;

    public:
    RadarSignal(int _numChannels, float *_signalStrength): numChannels(_numChannels) {

        signalStrength = new float[numChannels];
        for(int i=0;i<numChannels;++i){
            signalStrength[i] = _signalStrength[i];
        }
    }

    //Deep Copy
    RadarSignal(const RadarSignal &other): numChannels(other.numChannels){
        signalStrength = new float[other.numChannels];
        for(int i=0;i<numChannels;++i){
            signalStrength[i] = other.signalStrength[i];
        }
    }

    ~RadarSignal(){
        delete[] signalStrength;
    }

    float averageSignal() const {
        float sum = 0;
        for(int i=0;i<numChannels;++i){
            sum += signalStrength[i];
        }
        return sum/numChannels;
    }

    void boostSignalByValue(RadarSignal obj){
        for(int i=0;i<obj.getNumChannels();++i){
            obj.signalStrength[i] = obj.signalStrength[i]+5.0;
        }
        std::cout<<"\n----Inside boostSignalByValue-----\n";
        for(int i=0;i<obj.getNumChannels();++i){
            std::cout<<obj.signalStrength[i]<<"\n";
        }
    }

    void boostSignalByReference(RadarSignal &obj){
        for(int i=0;i<obj.getNumChannels();++i){
            obj.signalStrength[i] = obj.signalStrength[i]+5.0;
        }
        std::cout<<"\n----Inside boostSignalByRefernce-----\n";
        for(int i=0;i<obj.getNumChannels();++i){
            std::cout<<obj.signalStrength[i]<<"\n";
        }
    }

    int getNumChannels() const { return numChannels;}
    float getSignalStrength(int channel) const { return signalStrength[channel];}

};

void printRadarSignal(const RadarSignal &radar){
    std::cout<<"\n----Displaying Signal Strengths-----\n";
    for(int i=0;i<radar.getNumChannels();++i){
        std::cout<<radar.getSignalStrength(i)<<"\n";
    }
}

RadarSignal *createRadarSignalHeap(int num, float *signals) {
    return new RadarSignal(num, signals);
}

int main(){
    float signals[] = {55.5f, 48.2f, 60.1f, 52.6f};
    int channels = 4;
    RadarSignal *object = createRadarSignalHeap(channels, signals);

    printRadarSignal(*object);

    std::cout<<"\n---------Calling Boost function By Value--------\n";
    object->boostSignalByValue(*object);
    std::cout<<"\n---------After Calling Boost function By Value--------\n";
    printRadarSignal(*object);

    std::cout<<"\n---------Calling Boost function By Reference--------\n";
    object->boostSignalByReference(*object);
    std::cout<<"\n---------After Calling Boost function By Reference--------\n";
    printRadarSignal(*object);

    delete object;

    return 0;
}