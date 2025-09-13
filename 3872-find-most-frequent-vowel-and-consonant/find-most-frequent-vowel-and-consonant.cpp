class Solution {
public:
    bool isVowel(char &c){
        string vo = "aeiou";
        if(vo.find(c)!=-1)return true;
        return false;
    }
    int maxFreqSum(string s) {
        map<char,int>mpp;
        int maxv=-1,maxc=-1;
        for(char &c:s){
            mpp[c]++;
            if(isVowel(c)){
                maxv = max(maxv,mpp[c]);
            }
            else{
                maxc = max(maxc,mpp[c]);
            }
        }
        if(maxv!=-1 && maxc!=-1)return maxv+maxc;
        else if(maxv!=-1)return maxv;
        else if(maxc!=-1)return maxc;
        else return -1;
    }
};