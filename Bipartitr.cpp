#include <iostream>
using namespace std;

class Node {
private:
    int data;
    Node* next;

public:
    Node(int value) {
        data = value;
        next = nullptr;
    }

    // Getters and setters
    int getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }

    void setNext(Node* nextNode) {
        next = nextNode;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }

    // Display all nodes
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->getData() << " -> ";
            temp = temp->getNext();
        }
        cout << "NULL" << endl;
    }

    void insertAtBeginning(int val){
        Node * temp = new Node(val);
        temp->setNext(head);
        head = temp;
    }

    void insertAtPosition(int pos, int val){
       if(!head || !head->getNext()){
        return ;
       }
       Node * prev = nullptr;
       Node  * curr = head;
       while(pos){
        prev = curr;
        curr = curr->getNext();
        pos--;
       }
       Node * temp = new Node (val);
       prev->setNext(temp);
       temp->setNext(curr);
    }

    // Destructor to free memory
    ~LinkedList() {
        Node* current = head;
        Node* nextNode;
        while (current != nullptr) {
            nextNode = current->getNext();
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Linked List: ";
    list.display();

    return 0;
}

