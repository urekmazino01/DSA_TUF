#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], int visited[], vector<int> list){

    visited[node] =1;
    list.push_back(node);

    for(auto it: adj[node]){
        if(visited[it] != 1) dfs(it, adj,visited,list);
    }

}

vector<int> dfsForGraph(int n, vector<int> adj[]){

    int visited[n];
    for(int i=0;i<n;i++) visited[i] =0;

    int start =0;
    vector<int> list;

    dfs(start,adj, visited,list);
    return list;
    
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> adj[n];

    int u,v;
    for(int i=0;i<n;i++){
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // vector<int> visited[n];
    // for(int i=0;i<n;i++) {
    //     visited[i] = 0;
    // }

    vector<int> dfs=dfsForGraph(n,adj);
    return 0;
}