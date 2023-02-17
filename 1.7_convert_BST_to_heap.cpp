#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

// Given a Binary Search Tree. 
// Convert a given BST into a Special Max Heap with the condition that
//  all the values in the left subtree of a node should be less than 
//  all the values in the right subtree of the node. 
//  This condition is applied on all the nodes in the so converted Max Heap.

//---------------------------------------------------------------------------------------

// LOGIC :
            // step -> 1 get inorder of BST
            // step -> 2 populated it in postorder manner
class Solution{
  public:
    void in_o(Node* root,vector<int>& v){
        
        if(root == NULL){
            return ;
        }
        
        in_o(root->left,v);
        v.push_back(root->data);
        in_o(root->right,v);
    }
    void solve(Node* root,vector<int>&v,int &i){
        
        if(root == NULL){return;}
        
        solve(root->left,v,i);
        solve(root->right,v,i);
        
        root->data = v[i++];
    }
    void convertToMaxHeapUtil(Node* root)
    {
        
        vector<int> inorder;
        in_o(root,inorder);
        
        // populated inorder in form of postorder
        
        int index = 0;
        solve(root,inorder,index);
    }    
};