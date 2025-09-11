class Solution {
public:
    bool isVowel(char c){
        switch (c) {
            case 'A': case 'E': case 'I': case 'O': case 'U':
            case 'a': case 'e': case 'i': case 'o': case 'u':
                return true;
            default:
                return false;
        }
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