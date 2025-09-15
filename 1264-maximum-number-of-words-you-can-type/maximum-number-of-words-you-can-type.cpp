class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        vector<string>words;
        stringstream ss(text);
        string word;
        while(ss>>word){
            words.push_back(word);
        }
        set<char>st(brokenLetters.begin(),brokenLetters.end());
        vector<bool>wo(words.size(),true);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                if(st.find(words[i][j])!=st.end()){
                    wo[i]=false;
                    break;
                }
            }
        }
        int c=0;
        for(int i=0;i<words.size();i++){
            if(wo[i]==true)c++;
        }
        return c;
    }
};