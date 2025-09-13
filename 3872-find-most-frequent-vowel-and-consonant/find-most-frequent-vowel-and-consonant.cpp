class Solution {
public:
    bool isVowel(char &c){
        string vo = "aeiou";
        if(vo.find(c)!=-1)return true;
        return false;
    }
    int maxFreqSum(string s) {
        map<char,int>mpp;
        int maxv=0,maxc=0;
        for(char &c:s){
            mpp[c]++;
            if(isVowel(c)){
                maxv = max(maxv,mpp[c]);
            }
            else{
                maxc = max(maxc,mpp[c]);
            }
        }
        return maxc+maxv;
    }
};