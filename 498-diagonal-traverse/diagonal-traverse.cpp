class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int count=0;
        int i=0,j=0;
        // idea is traversing diagonally storing in list and reversing if even
        vector<vector<int>>diagmap(m+n);
        vector<int>diag;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diagmap[i+j].push_back(mat[i][j]);
            }
        }
        for(int i=0;i<diagmap.size();i++){
            if(i%2==0){
                reverse(diagmap[i].begin(),diagmap[i].end());
            }
            diag.insert(diag.end(),diagmap[i].begin(),diagmap[i].end());
        }
        return diag;
    }
};