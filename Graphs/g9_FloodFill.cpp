#include<iostream>
#include<vector>

using namespace std;


void dfs(int sr,int sc, int initialColor,int newColor, vector<vector<int>>& ans,vector<vector<int>> &image,int delRow[],int delCol[]){
        
        int n= ans.size();
        int m= ans[0].size();
         ans[sr][sc] =newColor;
        
        for(int i=0;i<4;i++){
            int nrow = sr+delRow[i];
            int ncol = sc+delCol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol] != newColor && image[nrow][ncol] == initialColor){
               
                dfs(nrow,ncol,initialColor,newColor,ans,image,delRow,delCol);
                
            }
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        
        int initialColor = image[sr][sc];
        vector<vector<int>> ans = image;
        
        int delRow[]={-1,0,1,0};
        int delCol[]={0,1,0,-1};
        
        dfs(sr,sc,initialColor,newColor,ans,image,delRow,delCol);
        return ans;
    }

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,m;
        vector<vector<int>> image(n, vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>image[i][j];
            }
        }
        int sr,sc,newColor;
        cin>>sr>>sc>>newColor;
        vector<vector<int>> ans = floodFill(image,sr,sc,newColor);

        for(auto i:ans){
            for(auto j:i) cout<<j<<" ";
            cout<<endl;
        }
    }
    return 0;
}