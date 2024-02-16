//Number of Provinces
#include<iostream>
#include<vector>
using namespace std;

void dfs(int start,vector<int> adj[],int visited[]){

    visited[start] =1;
    for(auto it: adj[start]){   
    if(!visited) dfs(it, adj,visited);
}
}

int numberOfProvince(int n, vector<int> adj[]){

    int visited[n];
    for(int i=0;i<n;i++) visited[i] =0;

    int count=0;

    for(int i=0;i<n;i++){
        if(visited[i] == 0)dfs(i,adj,visited);
        count++;
    }
    return count;

}

int main(){

    int n,m;
    cin>>n>>m;

    vector<int> adj[n];

    int u,v;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout<<numberOfProvince(n,adj);

    return 0;
}