
// The solution is based on defination of Heap only
// 1 --> Check for complete Binary tree
// 2 --> Check for Max heap property 
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
  int node_cnt(Node*root){
      
      if(root == NULL){return 0;}
      
      int left = node_cnt(root->left);
      int right = node_cnt(root->right);
      
      return left+right+1;
  }
  
  bool is_CBT(Node* root,int n,int i){
      
      if(root == NULL){return true;}
      
      else if(i>=n){return false;}
      
      else{
          bool left = is_CBT(root->left,n,2*i+1);
          bool right = is_CBT(root->right,n,2*i+2);
          
          return (left and right);
      }
      
  }
  bool is_Max_heap(Node* root){
      
      //leaf node
      if(root->left==NULL and root->right == NULL){return true;}
      
      if(root->left!=NULL and root->right == NULL){
          return(root->data > root->left->data);
      }
      
      if(root->left!=NULL and root->right!=NULL){
          return (root->data > root->left->data and root->data > root->right->data);
      }
  }
    
    bool isHeap(struct Node* root) {
        
        int n = node_cnt(root);
        bool is_cbt = is_CBT(root,n,0);
        
        if(is_cbt==false){return false;}
        
        bool is_max_heap = is_Max_heap(root);
        
        return (is_cbt and is_max_heap);
    }
};