class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        if(numRows==0)return {};
        for(int i=1;i<=numRows;i++){
            vector<int>temp;
            temp.push_back(1);
            int sol=1;
            for(int j=1;j<i;j++){
                sol = sol * (i-j);
                sol=sol/j;
                temp.push_back(sol);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};