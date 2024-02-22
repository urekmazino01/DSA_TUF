#include<iostream>
#include<queue>
#include<vector>

using namespace std;

vector<vector<int>> nearest(vector<vector<int>> grid){
    int n= grid.size();
    int m= grid[0].size();

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visited(n,vector<int>(m,0));
    vector<vector<int>> distance(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }
    }

    int delRow[]={-1,0,1,0};
    int delCol[]={0,1,0,-1};

    while(!q.empty()){
        int row=q.front().first.first;
        int col=q.front().first.second;
        int steps= q.front().second;

        q.pop();
        distance[row][col] = steps;

        for(int i=0;i<4;i++){
            int nrow= row+delRow[i];
            int ncol= col+delCol[i];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] == 0){
                q.push({{nrow,ncol},steps+1});
                visited[nrow][ncol] =1;
            }

        }

        
    }

    return distance;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m,-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }
        vector<vector<int>> ans=nearest(grid);
    }
}

