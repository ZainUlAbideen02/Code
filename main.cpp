#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

void mirror(Node * root){
    if (root == NULL) return;
    Node * temp = root->left;
    root->left = root->right;
    root->right= temp;
    mirror(root->left);
    mirror(root->right);
}

int arr[] = {1, 2, 3, 4, 5, 6, 7, -1, -1, -1, -1, -1, -1};
int idx = 0;
int n = sizeof(arr) / sizeof(arr[0]);

Node* orderwise(Node* root) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        if (idx >= n) {
            break;
        }

        Node* temp2 = q.front();
        q.pop();

        // Left child
        if (idx < n) {
            if (arr[idx] == -1) {
                temp2->left = NULL;
            } else {
                temp2->left = new Node(arr[idx]);
                q.push(temp2->left);
            }
            idx++;
        }

        // Right child
        if (idx < n) {
            if (arr[idx] == -1) {
                temp2->right = NULL;
            } else {
                temp2->right = new Node(arr[idx]);
                q.push(temp2->right);
            }
            idx++;
        }
    }

    return root;
}

void levelOrder(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
}

int main() {
    Node* root = new Node(arr[0]);  // ✅ first element is root
    idx = 1;                        // ✅ children start from index 1
    Node* temp = orderwise(root);

    cout << "Before Mirror (Level Order): ";
    levelOrder(temp);
    cout << endl;

    mirror(temp);

    cout << "After Mirror (Level Order): ";
    levelOrder(temp);
    cout << endl;
}