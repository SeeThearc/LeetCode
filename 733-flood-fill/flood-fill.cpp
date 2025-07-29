class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&img,int newcolor,int inicolor,int delrow[],int delcol[]){
        ans[row][col] = newcolor;
        int n = img.size();
        int m=img[0].size();
        for(int i=0;i<4;i++){
            int nrow = row+delrow[i];
            int ncol = col+delcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && img[nrow][ncol]==inicolor && ans[nrow][ncol]!=newcolor){
                dfs(nrow,ncol,ans,img,newcolor,inicolor,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans = image;
        int delrow[] = {0,0,-1,1};
        int delcol[] = {-1,1,0,0};
        int inicolor = image[sr][sc];
        dfs(sr,sc,ans,image,color,inicolor,delrow,delcol);
        return ans;
    }
};