 int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<pair<int,int>,int>> q;
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    visited[i][j] = 2;
                }
                else if(grid[i][j] == 1){
                    cnt1++;
                }
            }
        }

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1};

        int tm =0;
        int cnt =0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;

            tm = max(time,tm);
            q.pop();

            for(int i=0;i<4;i++){
                int nrow= row+delRow[i];
                int ncol= col+delCol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},time+1});
                    visited[nrow][ncol]= 2;
                    cnt++;
                }
            }


        }

        if(cnt1 != cnt){
            return -1;
        }
        return tm;
        
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> grid(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>grid[i][j];
            }
        }

        cout<<orangesRotting(grid);
    }
}