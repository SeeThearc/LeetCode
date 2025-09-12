class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiouAEIOU";
        int co=0;
        for(char &c:s){
            if(vowel.find(c)!=string::npos)co++;
        }
        if(co==0)return false;
        else return true;
    }
};