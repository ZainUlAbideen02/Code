#include <iostream>
#include <queue>
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

// Preorder array representation of tree (-1 means NULL)
int arr[] = {1, 2, 5, -1, 3, -1, -1};  
int idx = 0;

// Build tree from array (preorder format)
Node * BinaryTree(){
    int x = arr[idx++];   // take next element from array
    if(x == -1){
        return NULL;      // -1 means no node
    }

    Node * temp = new Node(x);
    temp->left = BinaryTree();   // build left subtree
    temp->right = BinaryTree();  // build right subtree
    return temp;
}

// Count total number of nodes in the tree (BFS)
int size(Node * root){
    if(root == NULL) return 0;

    queue<Node * >q;
    q.push(root);

    int count = 0;

    while (!q.empty())
    {
        Node* curr = q.front();
        q.pop();
        count++;  // count current node

        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }

    return count;
}

// Calculate sum of all nodes in the tree (BFS)
int sumf(Node * root){
    int sum= 0;
    Node * temp = root;
    queue<Node *>q;
    q.push(temp);
    while(!q.empty()){
        Node * temp1 = q.front();
        sum += temp1->data;  // add node value to sum
        if(temp1->left!=NULL){
            q.push(temp1->left);
        }
        if(temp1->right!=NULL){
            q.push(temp1->right);
        }
        q.pop();
    }

    return sum;
}

// Count the number of leaf nodes in the tree
int countLeafNodes(Node * root){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right==NULL){
        return 1;  // this node is a leaf
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Count how many children a node has (0, 1, or 2)
int countChildrenType(Node * root){
    if(root==NULL){
        return 0;
    }
    if(root->left == NULL && root->right==NULL){
        return 0;  // leaf has no children
    }
    else{
        if(root->left!=NULL && root->right==NULL){
            return 1;  // only left child
        }else if(root->left==NULL && root->right!=NULL){
            return 1;  // only right child
        }
        else{
            return 2;  // both children exist
        }
    }
    return countChildrenType(root->left)+countChildrenType(root->right);
}

int main(){
    Node * root = BinaryTree();
    cout << "Size of tree = " << size(root) << endl;
    cout << "Sum of tree = " << sumf(root) << endl;
    cout << "Leaf nodes = " << countLeafNodes(root) << endl;
    cout << "Children type (root) = " << countChildrenType(root) << endl;
}
