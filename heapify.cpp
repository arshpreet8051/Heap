#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Heapify function for max heap
void heapify(int arr [],int n,int i){
    
    // Heapify based on 1-indexing
    int target = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left < n and arr[left] > arr[target]){
        target = left;
    }
    if(right < n and arr[right] > arr[target]){
        target = right;
    }

    if(target!=i){
        swap(arr[target],arr[i]);
        heapify(arr,n,target);
    }
}



int main(){

int arr[6] = {-1,53,52,50,57,56};
int n = 6;
for(int i = n/2;i>0;i--){
    heapify(arr,n,i);
}

for(int i = 1;i<n;i++){
    cout<<arr[i]<<" ";
}


}
    






