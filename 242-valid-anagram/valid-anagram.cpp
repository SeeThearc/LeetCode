class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        map<char,int>mpp;
        for(char c:s){
            mpp[c]++;
        }
        for(char c:t){
            if(mpp[c]==0)return false;
            else mpp[c]--;
        }
        return true;
    }
};