class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        //use firstrow and firstcolumn to mark if row or column contains 0
        // we use first row for row and first column for column 
        // as matrix[0][0]appear twice so for column we create new variable col0 and we use    matrix[0][0 for row
        int col0=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    matrix[i][0]=0;
                    if(j!=0){
                        matrix[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }
        // mark from 1,1 to n,m
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=0){
                    if(matrix[i][0]==0||matrix[0][j]==0){
                        matrix[i][j]=0;
                    }
                }
            }
        }
        //check for first row and column
        if(matrix[0][0]==0){
            for(int j=0;j<m;j++){
                matrix[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                matrix[i][0]=0;
            }
        }
    }
};