class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length()==0){
            return true;
        }
        string s1;
        for(int i=0;i<s.length();i++){
            if(isalnum(s[i])){
                s1.push_back(tolower(s[i]));
            }
        }
        int k=s1.length();
        for(int i=0;i<k/2;i++){
            if(s1[i]!=s1[k-i-1]){
                return false;
            }
        }
        return true;
    }
};