class Solution {
public:
    int maxDistinct(string s) {
        set<char>st;
        for(char c:s){
            st.insert(c);
        }
        return st.size();
    }
};