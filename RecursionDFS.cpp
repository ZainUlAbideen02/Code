#include<iostream>
using namespace std;
#include<vector>

vector<int>DFS(int node,vector<int>adj[],vector<bool>&visited,vector<int>&ans){
    visited[node] = true;       
    ans.push_back(node);
    for(int i = 0 ; i<adj[node].size();i++){
        if(!visited[adj[node][i]]){
         return DFS(adj[node][i],adj,visited,ans);
        }
    }
    return ans;
}