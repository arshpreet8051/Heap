//Heap
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class heap{

    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;  // 0-th index te kuch ni rakna to apply formulas
        this->size = 0; 
    }

    void insert_in_heap(int data){

        size = size + 1;
        int index = size;
        arr[index] = data;

        // after insertion check for heap property

        while(index > 1){   // index > 1 coz to check with final root

        int parent = index/2;

        if(arr[parent] < arr[index]){
            swap(arr[parent] , arr[index]);
            index = parent;
        }
        else{
            return;
        }

        }
    }

    void print_heap(){

        for(int i = 1;i<=size;i++){  // NOTE: loop starts from '1'

            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }


    void delete_from_heap(){ // always deletes from root

        if(size == 0){cout<<"Nothing to delete ";return;}


        arr[1] = arr[size];
        size--;

        int index = 1;

        while(index < size){

            int left_child_index = 2*index;
            int right_child_index = 2*index+1;

            if(left_child_index < size and arr[left_child_index] > arr[index] and arr[left_child_index]){
                swap(arr[left_child_index],arr[index]);
                index = left_child_index;
            }
            else if(right_child_index < size and arr[right_child_index] > arr[index] and arr[right_child_index]){
                swap(arr[right_child_index],arr[index]);
                index = right_child_index;
            }
            else{
                return;
            }
        }

    }

    
};

// Heapify for max heap
    void heapify(int arr[],int size,int i){
        
        int target = i;
        int left = 2*i;
        int right = 2*i+1;

        if(left < size and arr[left] > arr[target]){
            target = left;
        }
        else if(right < size and arr[right] > arr[target]){
            target = right;
        }

        // check krla v index de koi fer badal hoi aa ke nahi

        if(target!=i){
            swap(arr[target],arr[i]);
            heapify(arr,size,target);
        }

    }

int main(){

    heap h;
    h.insert_in_heap(50);
    h.insert_in_heap(55);
    h.insert_in_heap(53);
    h.insert_in_heap(52);
    h.insert_in_heap(54);
    h.print_heap();

    h.delete_from_heap();
    h.print_heap();
    
    cout<<"Printing the array after Heapify"<<endl;
    int arr[5] = {-1,50,53,52,54};
    
    // Note: to apply heapify till halfway of array
    int n = 5;
    for(int i = 1;i<n/2;i++){
    heapify(arr,n,i);
    }

    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    }




    // 50 55 53 52 54
    return 0;
}



