class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string,char>mpp;
        map<char,string>rev;
        stringstream ss(s);
        string word;
        vector<string>words;
        while(ss>>word){
            words.push_back(word);
        }
        if(words.size()!=pattern.size())return false;
        for(int i=0;i<(int)words.size();i++){
            if(mpp.count(words[i]) && mpp[words[i]]!=pattern[i])return false;
            if (rev.count(pattern[i]) && rev[pattern[i]] != words[i])return false;
            mpp[words[i]]=pattern[i];
            rev[pattern[i]]=words[i];
        }
        return true;
    }
};