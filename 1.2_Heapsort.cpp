#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Based on 0-based-indexing

//ALGO -:
        // step -> 1) Apply Maz heap algo on given array
        // step -> 2) swap root(largest ele) with last ele in arr
        // step -> 3) now apply heapify algo on root node

void heap_sort(int arr[],int n){

    // step -> 1)
    Build_heap(arr,n);

    // step -> 2)
    
    for(int size = n-1;size>0;size--){
        swap(arr[size],arr[0]);
        
        // step -> 3)
        heapify(arr,n,0);
    }

}

void Build_heap(int arr[],int n){

    for(int i = n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
}

void heapify(int arr[],int n,int i){

    int target = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n and arr[left] > arr[target]){ // mtlb left bacha bada hai parent toh
        target = left;
    }

    if(right < n and arr[right] > arr[target]){ // mtlb right bacha bada hai parent toh
        target = right;
    }

    if(target != i){
        swap(arr[i] , arr[target]);
        heapify(arr,n,target);
    }


}