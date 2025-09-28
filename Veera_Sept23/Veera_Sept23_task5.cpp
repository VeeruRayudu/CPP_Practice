#include<iostream>
#include<cmath>

void bucketSort(int arr[], int size);
int findMax(int ar[], int size);

int main(){
    int array[] = {3, 40, 2, 26};
    bucketSort(array, 4);
}

void bucketSort(int arr[], int size){
    
    int maxNum = findMax(arr, size);
    int digits = (int)log10(maxNum)+1;
    int place = 1;
    for(int exp=0; exp<digits; exp++){
    int bucketArray[10][size];
    int bucketCount[10] = {0};
    for(int i=0;i<size;i++){
        int row = (arr[i]/place) % 10;
        bucketArray[row][bucketCount[row]] = arr[i];
        bucketCount[row]++;
    }
    
    int index = 0;
    for(int i=0; i<10; i++){
        for(int j=0; j<bucketCount[i]; j++){
            arr[index++] = bucketArray[i][j];
        }
    }
    place = place*10;
}
for(int i=0;i<size;i++){
    std::cout<<arr[i]<<", ";
}
}

int findMax(int ar[], int size){
    int max = 0;
    for(int i=0;i<size;i++){
        if(ar[i]>max){
            max = ar[i];
        }
    }
    return max;
}

// int findDigits(int num){
//     while(num>0){
//         int rem = num%10;
//     }
// }

// bool checkSorted(int ar[], int size){
//     int min = 0;
//     for(int i=0;i<size;i++){
//         if(ar[i]>min){
//             min = ar[i];
//         }else{
//             return false;
//         }
//     }
//     return true;
// }