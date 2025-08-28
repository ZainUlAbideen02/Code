#include <iostream>
#include<queue>
using namespace std;

class Node{
      public:
      int data;
      Node * left;
      Node * right;

      Node (int value){
        data = value;
        left = right = NULL;
      }
};

Node * BinaryTree(){
    int x ;
    cin>>x;
    if(x==-1){
        return NULL;
    }

    Node * temp = new Node(x);
    temp->left = BinaryTree();
    temp->right = BinaryTree();
    return temp;
}

int size(Node * root){
  Node * temp = root;
  queue<Node * >q;
  q.push(temp);
  
  int count = 1;

  while (!q.empty())
  {
    if(q.front()->left!=NULL){
        count++;
        q.push(q.front()->left);
    }
    if(q.front()->right!=NULL){
        count++;
        q.push(q.front()->right);
    }

    q.pop();
  }

  return count;

}

int main(){
    Node * root = BinaryTree();
    cout<<size(root);
}