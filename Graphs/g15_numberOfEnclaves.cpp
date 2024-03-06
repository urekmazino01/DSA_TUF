#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int numberOfEnclaves(vector<vector<int>> &grid){
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>> visited(n,vector<int>(m,0));
    queue<pair<int,int>> q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(grid[i][j] == 1){
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
    }

    int delRow[] = {-1,0,1,0};
    int delCol[] = {0,1,0,-1};

    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nrow = row+delRow[i];
            int ncol = col + delCol[i];

            if(nrow >=0 && ncol>=0 && nrow<=n-1 && ncol<=m-1 && visited[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                q.push({nrow,ncol});
                visited[nrow][ncol] = 1;

            }
        }



    }

    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && visited[i][j] == 0){
                cnt++;
            }
        }
    }

    return cnt;


}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> grid(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }

        cout<<numberOfEnclaves(grid)<<endl;

    }
}