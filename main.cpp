#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
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
    cout<<root->data<<" ";


}

void leftViewOfBinaryTree(Node * root){
    queue<Node *>q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        for(int i = 0 ; i<n;i++){
            Node * temp = q1.front();
            q1.pop();
            if(i==0){
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right){
                q1.push(temp->right);
            }
        }
    }
}

void rightViewOfBinaryTree(Node * root){
    queue<Node *>q1;
    q1.push(root);
    while(!q1.empty()){
        int n = q1.size();
        for(int i = 0 ; i<n;i++){
            Node * temp = q1.front();
            q1.pop();
            if(i==n-1){
                cout<<temp->data<<" ";
            }
            if(temp->left){
                q1.push(temp->left);
            }
            if(temp->right){
                q1.push(temp->right);
            }
        }
    }
}

void preIterative(Node * root){
    stack<Node * >s1;
    s1.push(root);

    while(!s1.empty()){
        Node * temp = s1.top();
        s1.pop();
        cout<<temp->data<<" ";
        if(temp->right){
            s1.push(temp->right);
        }
        if(temp->left){
            s1.push(temp->left);
        }
    }
}

void postIterative(Node * root){
    stack<Node * >s1;
    s1.push(root);
    vector<int>v1;

    while(!s1.empty()){
        Node * temp = s1.top();
        s1.pop();
        v1.push_back(temp->data);
        if(temp->left){
            s1.push(temp->left);
        }
        if(temp->right){
            s1.push(temp->right);
        }
    }
    reverse(v1.begin(),v1.end());

    for(int i:v1){
        cout<<i<<" ";
    }
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