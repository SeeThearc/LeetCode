class Solution {
public:
    bool isVowel(char c){
        int ans = string("AEIOUaeiou").find(c);
        if(ans>=0)return true;
        return false;
    }
    string sortVowels(string s) {
        vector<char>vowel;
        for(char c:s){
            if(isVowel(c)){
                vowel.push_back(c);
            }
        }
        sort(vowel.begin(),vowel.end());
        int i=0;
        for(char &c:s){
            if(isVowel(c)){
                c = vowel[i];
                i++;
            }
            if(i==vowel.size())break;
        }
        return s;
    }
};