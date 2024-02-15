#include<iostream>
#include<vector>
using namespace std;

vector<int> dfsForGraph(int n, vector<int> adj[]){
    
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

    vector<int> dfs=dfsForGraph(n,adj);
    return 0;
}