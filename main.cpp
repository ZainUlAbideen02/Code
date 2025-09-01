#include<iostream>
using namespace std;


class Node{
   public:
   int data;
   Node * left ;
   Node * right;

   Node(int value){
    data = value;
    left = NULL;
    right = NULL;
   }
};


void BinaryTree(Node * root){

    int x = 0; 
    cin>>x;

    if(x!=-1){
      root->left = new Node(x);
      BinaryTree(root->left);
    }
    else{
        root->left = NULL;
        return ;
    }
    cin>>x;
    if(x!=-1){
      root->right = new Node(x);
      BinaryTree(root->right);
    }
    else{
        root->right=NULL;
        return;
    }
    
}

void preOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node * root){
    if(root==NULL){
        return ;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";// 5 2 4 -1 -1 6 -1 -1 3 -1 -1
    //5 2 4 -1 -1 6 -1 -1 -1


}

int main(){
    int val;
    cin >> val;
    Node* root = new Node(val);
    BinaryTree(root);
    cout<<endl;
    preOrderTraversal(root);
    cout<<endl;
    inOrderTraversal(root);
    cout<<endl;
    postOrderTraversal(root);
}