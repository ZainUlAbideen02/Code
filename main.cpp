#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    queue<Node*> q1;
    Node* root = new Node(10);
    q1.push(root);

    int le = 0, ri = 0;

    while (!q1.empty()) {
        Node* curr = q1.front();
        q1.pop();

        cin >> le;
        if (le != -1) {
            curr->left = new Node(le);
            cout << le << " has been added on left of " << curr->data << endl;
            q1.push(curr->left);
        } else {
            cout << "Left skipped for " << curr->data << endl;
        }

        cin >> ri;
        if (ri != -1) {
            curr->right = new Node(ri);
            cout << ri << " has been added on right of " << curr->data << endl;
            q1.push(curr->right);
        } else {
            cout << "Right skipped for " << curr->data << endl;
        }
    }

    return 0;
}
