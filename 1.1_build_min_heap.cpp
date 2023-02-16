#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Build Min Heap
// Input array is based on 0-based-indexing

void heapify(vector<int>& arr,int n,int i){

    int target = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n and arr[left] < arr[target]){ // mtlb parent to chota child
        target = left;
    }
    if(right < n and arr[right] < arr[target]){
        target = right;
    }


    if(target != i){ // mtlb kuch to change hoa ha
        swap(arr[target],arr[i]);
        heapify(arr,n,target);
    }

}


vector<int> build_min_heap(vector<int> arr){


    int n = arr.size();

    for(int i = n/2;i>=0;i--){
        heapify(arr,n,i);
    }

    return arr;
}

// Another approach using priority queue
// TLE

vector<int> buildMinHeap(vector<int> &arr)
{
    priority_queue<int,vector<int>,greater<int>>pq;

    for(int i = 0;i<arr.size();i++){
        pq.push(arr[i]);
    }

    vector<int> ans;

    for(int i = 0;i<arr.size();i++){
        ans.push_back(pq.top());
        pq.pop();
    }

    return ans;
}