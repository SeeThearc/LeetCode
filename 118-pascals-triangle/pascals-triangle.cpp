class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int row=1;row<=numRows;row++){
            vector<int>temp;
            temp.push_back(1);
            int sol=1;
            for(int col=1;col<row;col++){
                sol=sol*(row-col);
                sol=sol/col;
                temp.push_back(sol);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};