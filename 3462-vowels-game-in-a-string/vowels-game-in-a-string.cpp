class Solution {
public:
    bool doesAliceWin(string s) {
        string vowel = "aeiouAEIOU";
        for(char &c:s){
            if(vowel.find(c)!=string::npos)return true;
        }
        return false;
    }
};