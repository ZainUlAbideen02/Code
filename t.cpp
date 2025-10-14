#include <iostream>
using namespace std;

class Node
{
      private:
              int element;
              Node* next_node;
      public:
             Node(int i=0, Node *n= nullptr);

             int retrieve() const;
             Node* next() const;
             
             void setnext(Node *n);
             void setelement(int);
                   
};

Node::Node(int i, Node *n): element(i),next_node(n) 
{
         //empty constructor     
}
int Node::retrieve() const
{
    return element;
}
Node* Node::next() const
{
      return next_node;
}

void Node::setelement(int i)
{
     element=i;
}
void Node::setnext(Node * n)
{
     next_node=n;
}

class linkedlist
{
    private: 
        Node* list_head;
    public:
        linkedlist()
        {
            list_head=nullptr;
        }
        bool empty() const;
        Node *head() const;
        int front() const;
        void display() const;
        int size() const;
        int count(int) const;
        int end() const;
        
        
        void push_front(int);
        int pop_front();
        void push_end(int);
        void pop_end();
        int erase(int);
        
};
bool linkedlist::empty() const
{
    return (list_head==nullptr);
}
Node* linkedlist::head() const
{
    return list_head;
}
int linkedlist::front() const
{
    if (empty())
        throw "Underflow";
    else
        return head()->retrieve();
}
void linkedlist::push_front(int n)
{
    list_head=new Node(n,head());
}
void linkedlist::display() const
{
    cout << "\nList: ";
    for (Node * ptr=head(); ptr!=nullptr; ptr=ptr->next())
    {
        cout << ptr->retrieve() << "\t";
    }
}
int linkedlist::pop_front()
{
    if(empty())
    {
        throw "Underflow";
    }
    int e=front();
    Node *ptr=head();
    list_head=list_head->next();
    delete ptr;
    ptr=nullptr;
    return e;
}

int linkedlist::size() const
{
    int node_count=0;
    for (Node * ptr=head(); ptr!=nullptr; ptr=ptr->next())
    {
        node_count++;
    }
    return node_count;
}
int linkedlist::count(int n) const
{
    int node_count=0;
    for (Node * ptr=head(); ptr!=nullptr; ptr=ptr->next())
    {
        if (ptr->retrieve()==n)
            node_count++;
    }
    return node_count;
}

int linkedlist::end() const
{
    if (empty())
        throw "Underflow";
    Node *ptr;
    for (ptr=head(); ptr->next()!=nullptr; ptr=ptr->next())
    {
        
    }
    return ptr->retrieve();
}
int linkedlist::erase(int n)
{
    if(empty())
        throw "Underflow";
    int node_count=0;
    if(head()->retrieve()==n)
    {
        pop_front();
        node_count++;
    }
    
    Node *prev=head();
    for (Node * ptr=head(); ptr!=nullptr; ptr=ptr->next())
    {
        if(ptr->retrieve()==n)
        {    
            if(head()->retrieve()==n)
            {
                pop_front();
                node_count++;
            }
            else
            {
                //cout << prev->next()->retrieve();
            //display();
            prev->setnext(ptr->next());
            //display();
            //cout << prev->next()->retrieve();
            delete ptr;
            ptr=prev;
            //display();
            node_count++;
            //return node_count;
            //ptr=nullptr;
            //prev=prev;
           // display();
            }
            
        }
        prev=ptr;
    }
    return node_count;
}
int main()
{
   linkedlist l;
   l.push_front(6);
   l.push_front(4);
   l.push_front(3);
   l.push_front(8);
   l.push_front(3);
   l.push_front(3);
   l.display();
   //cout << l.size();
   l.erase(3);
   //cout << l.empty();
   //cout << l.front();
   l.display();
   //cout << l.size();
   //cout << l.count(8);
   //cout << l.end();
   //l.pop_front();
   //cout << l.count(8);
   //cout << l.size();
   //l.display();
    return 0;
}