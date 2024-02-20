#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node,int parent,vector<int> adj[],int visited[]){
    visited[node]=1;
    for(auto it:adj[node]){
        if(!visited[it]){
            if(dfs(it,node,adj,visited)) return true;
            
        }
        else if(it!=parent) return true;
    }

    return false;
        
        
}


bool isCycle(int n, vector<int> adj[]) {
        // Code here
    int visited[n];
    for(int i=0;i<n;i++) visited[i] =0;
        
    for(int i=0;i<n;i++){
        if(!visited[i])  return dfs(i,-1,adj,visited);
    }
    return false;
        
}

int main(){

    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<int> adj[n];
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return isCycle(n,adj);
    }
    return 0;
}