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
};

int main(){

    heap h;
    h.insert_in_heap(50);
    h.insert_in_heap(55);
    h.insert_in_heap(53);
    h.insert_in_heap(52);
    h.insert_in_heap(54);
    h.print_heap();



    // 50 55 53 52 54
    return 0;
}



