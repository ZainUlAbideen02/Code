#include<iostream>
using namespace std;

void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

void insertAtFirst(int arr[],int size,int value)
{
    for(int i=size-1;i>=0;i--){
        arr[i+1]=arr[i];
    }
    arr[0]=value;
    display(arr,size+1);
}

void insertAtLast(int arr[],int size,int value)
{
    arr[size]=value;
    display(arr,size+1);
}

void insertAtMiddle(int arr[],int size,int value,int pos)
{
    for(int i=size-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=value;
    display(arr,size+1);
}

void deleteAtFirst(int arr[],int size)
{
    for(int i=0;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    display(arr,size-1);
}

void deleteAtLast(int arr[],int size)
{
    display(arr,size-1);
}

void deleteAtMiddle(int arr[],int size,int pos)
{
    for(int i=pos;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    display(arr,size-1);
}

int search(int arr[],int n,int x)
{
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            return i;
        }
    }
    return -1;
}


int main()
{
    int arr[40];
    int n;
    cout<<"Enter the size: "<<endl;
    cin>>n;     
    cout<<"Enter the element: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    display(arr,n);

    cout<<"Enter the number to insert at first: "<<endl;
    int x;
    cin>>x;
    insertAtFirst(arr,n,x);

    cout<<"Enter the number to insert at last: "<<endl;
    cin>>x;
    insertAtLast(arr,n,x);

    cout<<"Enter the number to insert at middle and position: "<<endl;
    int pos;
    cin>>x>>pos;
    insertAtMiddle(arr,n,x,pos);

    cout<<"Delete at first "<<endl;
    deleteAtFirst(arr,n);

    cout<<"Delete at last "<<endl;
    deleteAtLast(arr,n);

    cout<<"Delete at middle "<<endl;
    cin>>pos;
    deleteAtMiddle(arr,n,pos);

    cout<<"Enter the number to search "<<endl;
    cin>>x;
    int re=search(arr,n,x);
    if(re==-1){
        cout<<"Element not Present "<<endl;
    }
    else{
        cout<<"Element found at index "<<re<<endl;
    }

}