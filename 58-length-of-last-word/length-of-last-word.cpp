class Solution {
public:
    int lengthOfLastWord(string s) {
        string stri;
        stringstream ss(s);
        vector<string>str;
        while(getline(ss,stri,' ')){
            str.push_back(stri);
        }
        int i = str.size()-1;
        while(i>=0){
            if(str[i].size()>0)return str[i].size(); 
            i--;
        }
        return 0;
    }
};