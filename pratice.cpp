#include<iostream>
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

    bool empty(){
        if(head==nullptr){
            return 1;
        }
        else{
            return 0;
        }
    }

    int size(){
        int sz = 0;
        if(head==nullptr){
            return 0;
        }
        else{
            Node * temp = head;
            while(temp!= nullptr){
                sz++;
                temp = temp->getNext();
            }
            return sz;
        }
    }

    int front(){
        if(head==nullptr){
            cout<<"Head is null, No value";
            return -1;
        }
        else{
            return head->getData();
        }
    }

    int end(){
        if(head==nullptr){
             cout<<"Head is null, No value";
            return  -1;
        }else{
            Node * temp = head;
            int en  = 0;
            while(temp->getNext()!=nullptr){
                temp = temp->getNext();
            }
            return temp->getData();
        }
    }

    void pushfront(int value){
        Node * temp = new Node(value);
        if(head==nullptr){
            head = temp;
        }
        else{
            temp->setNext(head);
            head = temp;
        }
    }

    void pushend(int value){
        Node * temp = new Node(value);
        if(head==nullptr){
            head = temp;
        }
        else{
            Node * prev = head;
            while(prev->getNext()!=nullptr){
                prev = prev->getNext();
            }
            prev->setNext(temp);
        }
    }

    int popfront(){
        if(!head){
            cout<<"No head exists"<<endl;
            return -1;
        }
        else{
            Node * temp = head;
            int value = head->getData();
            head = head->getNext();
            delete temp;
            return value;
        }
    }

    int popend(){
        if(!head){
            cout<<"No head exists"<<endl;
            return -1;
        }
         if (head->getNext() == nullptr) {
        int value = head->getData();
        delete head;
        head = nullptr;
        return value;
    }
        else{
            Node  * prev = NULL;
            Node * curr = head;
            while(curr->getNext()!=nullptr){
                prev = curr;
                curr = curr->getNext();
            }
            int value = curr->getData();
            prev->setNext(NULL);
            delete curr;
            return value;
        }
    }

    int erase(int pos){
        if(!head){
            cout<<"No head exists"<<endl;
            return -1;
        }
        Node * temp = head;
        int siz = 0;
        while(temp!= nullptr){
            siz++;
            temp = temp->getNext();
        }
        if(pos>siz){
            cout<<"This position cannot exits or the size of linklist is small than your enterend position."<<endl;
            return -1;
        }
        Node * prev = NULL;
        Node * curr = head;
        while(pos>0){
            prev = curr;
            curr = curr->getNext();
            pos--;
        }
        prev->setNext(curr->getNext());
        int value = curr->getData();
        delete curr;
        return value;
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

class stack{
    LinkedList l;
    public:

    bool empty(){
        if(l.empty()){
            return 1;
        }  
        return 0;
    }

    int top(){
        if(l.empty()){
            cout<<"Your stack is empty."<<endl;
            return -1;
        }
        else{
            return l.end();
        }

    }

    void push(int value){
        l.pushend(value);
    }

    int pop(){
        return l.popend();
    }

}

int main(){

}
