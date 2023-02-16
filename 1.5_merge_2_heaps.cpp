#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Simply Based on Heapify algorithm

class Solution{
    public:
    void heapify(vector<int>&a,int n,int i){
        int target = i;
        int left = 2*i+1;
        int right = 2*i+2;
        
        if(left<n and a[left] > a[target]){
            target = left;
        }
        if(right < n and a[right] > a[target]){
            target = right;
        }
        
        if(target!=i){
            swap(a[i],a[target]);
            heapify(a,n,target);
        }
    }
    void build_heap(vector<int>&a){
        
        int n = a.size();
        
        for(int i=n/2-1;i>=0;i--){
            heapify(a,n,i);
        }
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        for(int i = 0;i<m;i++){
            a.push_back(b[i]);
        }
        
        build_heap(a);
        
        return a;
    }
};