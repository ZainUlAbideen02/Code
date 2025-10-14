#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
     int V;
     int E;
     cin>>V>>E;
 
     vector<vector<int> > adj(V);

     for (int i = 0; i <E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }



    stack<int>q1;
    q1.push(0);

    vector<int>visited(V,0);
    vector<int>ans;
    int node ;
    visited[0]=1;
    while(!q1.empty()){
       node = q1.top();
       q1.pop();
       ans.push_back(node);

       for(int i = 0 ;i<adj[node].size();i++){
          if(!visited[adj[node][i]]){
            q1.push(adj[node][i]);
            visited[adj[node][i]] = 1;
       }
    }


}
}