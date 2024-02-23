#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<int>> &visited, int delRow[],int delCol[],vector<vector<char>> &mat){

    int n=mat.size();
    int m=mat[0].size();

    for(int i=0;i<4;i++){
        int nrow=row+delRow[i];
        int ncol = col +delCol[i];
        if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol] ==0 && mat[nrow][ncol] =='O'){
            dfs(nrow,ncol,visited,delRow,delCol,mat);
        }
    }

}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat){
    int delRow[] ={-1,0,1,0};
    int delCol[] ={0,1,0,-1};

    vector<vector<int>> visited(n,vector<int>(m,0));

    for(int j=0;j<m;j++){
        //first row
        if(visited[0][j] == 0 && mat[0][j] == 'O'){
             dfs(0,j,visited,delRow,delCol,mat);
        }

        //last row
        if(visited[n-1][j] == 0 && mat[n-1][j] == 'O'){
            dfs(n-1,j,visited,delRow,delCol,mat);
        }
       
    }

    for(int i=0;i<n;i++){
        if(visited[i][0] == 0 && mat[i][0] == 'O'){
            dfs(i,0,visited,delRow,delCol,mat);
        }

        if(visited[i][m-1] == 0 && mat[i][m-1] == 'O'){
            dfs(i,m-1,visited,delRow,delCol,mat);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && mat[i][j] == 'O'){
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
    

}

int main(){

    int tc;
    cin>>tc;
    while(tc--){

        int n,m;
        cin>>n>>m;

        vector<vector<char>> mat(n,vector<char>(m,'.'));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>mat[i][j];
            }
        }

        vector<vector<char>> ans = fill(n,m,mat);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }
    }

    return 0;
}