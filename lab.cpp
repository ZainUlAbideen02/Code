#include<iostream>
#include<vector>
using namespace std;

int main()
{
     int V;
     int E;
     cin>>V>>E;
 
     vector<vector<int>> adj(V, vector<int>(V, 0));

     for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }


    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

}