class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string s="";
        for(auto word:words){
            int sum=0;
            for(char c:word){
                sum+=weights[c-'a'];
            }
            sum %= 26;
            s += ('z' - sum);
        }
        return s;
    }
};