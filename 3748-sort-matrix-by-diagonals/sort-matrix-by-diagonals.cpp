class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int,priority_queue<int,vector<int>>>maxheap;
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>minheap;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-j<0){
                    minheap[i-j].push(grid[i][j]);
                }
                else{
                    maxheap[i-j].push(grid[i][j]);
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i-j<0){
                    grid[i][j] = minheap[i-j].top();
                    minheap[i-j].pop();
                }
                else{
                    grid[i][j] = maxheap[i-j].top();
                    maxheap[i-j].pop();
                }
            }
        }
        return grid;
    }
};