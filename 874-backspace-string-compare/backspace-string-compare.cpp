class Solution {
public:
    string find(string s){
        string temp="";
        stack<char>st;
        for(int i=0;i<s.size();i++){
            if(s[i]!='#'){
                st.push(s[i]);
            }
            else if(s[i]=='#' && !st.empty()){
                st.pop();
            }
        }
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        return temp;
    }
    bool backspaceCompare(string s, string t) {
        string s1 = find(s);
        string t1 = find(t);
        return s1==t1;
    }
};