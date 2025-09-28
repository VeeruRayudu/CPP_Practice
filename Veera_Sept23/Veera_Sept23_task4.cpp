#include<iostream>
#include<vector>

const int N = 20;
bool floorArray[N][N] = {false};
int x = 0, y=0;
bool pendown = false;
int dir = 0;

void moveForward(int steps);
void turnRight();
void turnLeft();
void printFloor();

int main(){
    std::vector<std::vector<int>> cmd = {
        {2},
        {5,12},    
        {3},       
        {5,12},   
        {3},       
        {5,12},    
        {3},      
        {5,12},    
        {1},       
        {6},       
        {9}
    };

    for(auto _cmd : cmd){
        switch (_cmd[0])
        {
        case 1: pendown = false; break;
        case 2: pendown = true; break;
        case 3: turnRight(); break;
        case 4: turnLeft(); break;
        case 5: moveForward(_cmd[1]); break;
        case 6: printFloor(); break;
        case 9: std::cout<<"end of program \n"; return 0;
        default: std::cout<<"Invalid command \n"; break;
        }
    }
    return 0;

}

void moveForward(int steps){
    for(int i=0;i<steps;i++){
        if(pendown && x >= 0 && x < N && y >= 0 && y<N){
            floorArray[y][x] = true;
        }

        switch (dir){
        case 0: x = (x+1 < N) ? x+1 : x; break;
        case 1: y = (y+1 < N) ? y+1 : y; break;
        case 2: x = (x-1 >= 0) ? x-1 : x; break;
        case 3: y = (y-1 >= 0) ? y-1 : y; break;        
        }
    }
}

void turnRight(){
    dir = (dir + 1)%4;
}

void turnLeft(){
    dir = (dir + 3)%4;
}

void printFloor(){
    for(int row = 0; row < N; row++){
        for(int col = 0; col < N; col++){
            std::cout<<(floorArray[row][col] ? "*" : " ");
        }
        std::cout<<"\n";
    }
}