class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int ans=0;
        int m = mat.size();
        int n = mat[0].size();
        vector<int>height(n,0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0)height[j]=0;
                else height[j]++;
            }
            for(int j=0;j<n;j++){
                int min_height = height[j];
                for(int k=j; k>=0 && min_height>0;k--){
                    min_height = min(min_height,height[k]);
                    ans+=min_height;
                }
            }
        }
        return ans;
    }
};