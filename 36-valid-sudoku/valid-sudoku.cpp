class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>>rows(9),cols(9),boxes(9);
        int n = board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char c = board[i][j];
                if(c=='.')continue;
                if(rows[i].count(c))return false;
                rows[i].insert(c);
                if(cols[j].count(c))return false;
                cols[j].insert(c);
                int ind = i/3 * 3 + j/3;
                if(boxes[ind].count(c))return false;
                boxes[ind].insert(c); 
            }
        }
        return true;
    }
};