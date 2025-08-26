#include <iostream>
#include<queue>
using namespace std;

int main(){
    int array [] = {3,6,2,7,8,11};
    int size = 6 ;
    int k = 3;

    queue<int>q1;
    queue<int>q2;

    for(int i = 0 ; i < size-2;i++){
        for(int j = i ; j<3+i;j++){
            q1.push(array[j]);
        }
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
        cout<<endl;
    }
}

