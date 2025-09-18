#include<iostream>

class CameraConfig{
    private:
    int numModes;
    int *resolutionWidth;
    int *resolutionHeight;

    public:
    CameraConfig(int _numModes, int *_resolutionWidth, int *_resolutionHeight): numModes(_numModes){

        resolutionWidth = new int[numModes];
        resolutionHeight = new int[numModes];

        for(int i=0;i<numModes;i++){
            resolutionWidth[i] = _resolutionWidth[i];
            resolutionHeight[i] = _resolutionHeight[i];
        }
    }

    //copy constructor
    CameraConfig(const CameraConfig &other): numModes(other.numModes){
        resolutionWidth = new int[numModes];
        resolutionHeight = new int[numModes];

        for(int i=0;i<numModes;i++){
            resolutionWidth[i] = other.resolutionWidth[i];
            resolutionHeight[i] = other.resolutionHeight[i];
        }
    }

    //Deconstructor

    void printConfig() const {
        std::cout<<"Camera Modes and Resolution\n";
        for(int i=0;i<numModes;i++){
            std::cout<<"Mode "<<i<<" resolution: "<<resolutionWidth[i]<<"x"<<resolutionHeight[i]<<std::endl;
        }
    }

    bool isHigherResolution(int mode1, int mode2) const {
        int res1 = this->resolutionWidth[mode1] * this->resolutionHeight[mode1];
        int res2 = this->resolutionWidth[mode2] * this->resolutionHeight[mode2];
        return res1 > res2;
    }

    int getNumModes() const {
        return numModes;
    }
    int getResolutionWidth(int mode) const {
        return resolutionWidth[mode];
    }
    int getResolutionHeight(int mode) const {
        return resolutionHeight[mode];
    }

};

void printCameraConfig(const CameraConfig &config){
    config.printConfig();
}

bool globalCompareResolution(const CameraConfig &config, int m1, int m2){
    return config.isHigherResolution(m1,m2);
}

int main(){
    int numModes = 3;
    int resolutionWidth[] = {1920, 1280, 3840};
    int resolutionHeight[] = {1080, 2160, 2160};

    CameraConfig config(numModes, resolutionWidth, resolutionHeight);

    std::cout<<"\n---------Camera Config-------\n";
    printCameraConfig(config);

    std::cout<<"\n---------comparision using member function-----------";
    if(config.isHigherResolution(0,2)){
        std::cout<<"\nMode 0 is greater than Mode 2"<<std::endl;
    }else{
        std::cout<<"\nMode 2 is greater than Mode 0"<<std::endl;
    }

    std::cout<<"\n---------comparision using member function-----------";
    if(globalCompareResolution(config, 0, 2)){
        std::cout<<"\nMode 0 is greater than Mode 2";
    }else{
        std::cout<<"\nMode 2 is greater than Mode 0";
    }

    return 0;

}



