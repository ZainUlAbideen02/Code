#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
   
  priority_queue<int,vector<int>,less<int>>p1;
  priority_queue<pair<int,int>,vector<pair<int,int>, greater<pair<int,int> > >>p2;
  

   p2.push({10,1});
   p2.push({3,2});
   p2.push({7,5});
   p2.push({2,4});


   while(!p2.empty()){
    cout<<p2.top().first()<<" "<<p2.top().second()<<endl;
    p2.pop();
   }



}