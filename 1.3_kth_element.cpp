#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// for k-th smallest --> use max heap
// for k-th largest  --> use min heap

// Given a N x N matrix, 
// where every row and column is sorted in non-decreasing order. 
// Find the kth smallest element in the matrix.
int k_th_smallest_element(int arr[1000][1000],int n,int k){

    priority_queue<int> pq;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            pq.push(arr[i][j]);
            //NOTE;
            if(pq.size()>k){pq.pop();}
        }
    }
    return pq.top();
}

int k_th_largest_element(int arr[1000][1000],int n,int k){

    priority_queue<int,vector<int>,greater<int>> pq; // min heap
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            pq.push(arr[i][j]);
            //NOTE;
            if(pq.size()>k){pq.pop();}
        }
    }
    return pq.top();
}

