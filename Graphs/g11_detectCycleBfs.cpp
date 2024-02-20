#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool detectCycle(int src,vector<int> adj[],int visited[]){
        visited[src] =1;
        queue<pair<int,int>> q;
        
        q.push({src,-1});
        while(!q.empty()){
            int parent = q.front().second;
            int node = q.front().first;
            q.pop();
            
            for(auto it:adj[node]){
                if(!visited[it]){
                    q.push({it,node});
                    visited[it]=1;
                }else if( parent != it){
                    return true;
                }
            }
        }
        return false;
        
    }


bool isCycle(int n, vector<int> adj[]) {
        // Code here
    int visited[n];
    for(int i=0;i<n;i++) visited[i] =0;
        
    for(int i=0;i<n;i++){
        if(!visited[i]){
            if(detectCycle(i,adj,visited)) return true;
        }
            
    }
    return false;
        
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m ;
        cin>>n>>m;
        vector<int> adj[n];
        int u,v;
        for(int i=0;i<m;i++){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(v);

        }
        return isCycle(n,adj);
    }
    return 0;
}