#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsf(int n,vector<int> adj[]){
    vector<int> bfs;
    int vis[n+1];
    for(int i=0;i<n+1;i++) vis[i] =0;
    vis[0]=1;
    queue<int> q;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }

    }

    return bfs;
}

int main(){

    int n,m;
    cin>>n>>m;
    int u,v;

    vector<int> adj[n];
    for(int i=0;i<m;i++){
        
        cin>>u>>v; 
        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    //1 2 6 3 4 7 8 5
    //starting node 6
    //6 1 8 7 2 5 3 4

    //Queue FIFO

    vector<int> bfst = bfsf(n,adj);



    return 0;
}