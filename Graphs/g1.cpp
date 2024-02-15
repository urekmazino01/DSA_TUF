#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    // Declare variables for the number of vertices (n) and edges (m)
    int n, m;
    // Input the number of vertices and edges
    cin >> n >> m;

    // Declare an array of vectors to represent the adjacency list
    vector<int> adj[n+1];

    // Loop to input the edges and build the adjacency list
    for(int i = 0; i <m; i++){
        int u, v;
        // Input the vertices of an edge
        cin >> u >> v;
        // Add the edge to the adjacency list (since the graph is undirected, add to both u and v)
        adj[v].push_back(u);
        adj[u].push_back(v);
    }

    // The adjacency list representation is now stored in the 'adj' array

    return 0;
}
