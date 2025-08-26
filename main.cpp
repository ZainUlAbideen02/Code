#include <iostream>
#include<queue>
using namespace std;

int main(){
    int array [] = {2,-3,-4,-2,7,8,9,-10};
    int size = 8 ;
    int k = 3;

    queue<int>q1;

    for(int i = 0 ; i <= size-k;i++){
        for(int j = i ; j<k+i;j++){
            if(array[j]<0){
            q1.push(array[j]);
            break;
            }
        }
        while(!q1.empty()){
            cout<<q1.front()<<" ";
            q1.pop();
        }
        cout<<endl;
    }
}

