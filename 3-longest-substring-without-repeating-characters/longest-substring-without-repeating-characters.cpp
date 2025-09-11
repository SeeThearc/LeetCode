class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        set<char>st;
        int i=0,j=0;
        while(j<s.size()){
            if(st.find(s[j])==st.end()){
                st.insert(s[j]);
                res = max(res,j-i+1);
                j++;
            }
            else{
                st.erase(s[i]);
                i++;
            }
        }
        return res;
    }
};