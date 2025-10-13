class Solution {
public:
    int anagram(string s1,string s2){
        if(s1.size()!=s2.size()){
            return 0;
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        int i = 1;
        while(i<words.size()){
            if (anagram(words[i-1],words[i])){
                words.erase(words.begin()+i);
            }
            else{
                i++;
            }
        }
        return words;
    }
};