#include<iostream>

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}


int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int i = start - 1;

    for(int j=start;j<end;j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[end]);
    return i+1;
}


void quickSort(int arr[], int start, int end){
    if(start < end){
        int partitionIndex = partition(arr, start, end);
        
        quickSort(arr, start, partitionIndex-1);
        quickSort(arr, partitionIndex+1, end);
    }
}

int main(){
    int arr[] = {37, 10, 8, 9, 1, 5};
    int n = sizeof(arr)/sizeof(arr[0]);

    quickSort(arr, 0, n-1);
    
    std::cout<<"Sorted array: ";
    for(int i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }

    return 0;
}