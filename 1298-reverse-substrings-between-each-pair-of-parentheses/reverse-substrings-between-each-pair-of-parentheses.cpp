class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int k=0;
        int n = s.size();
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(k);
            }
            else if(isalpha(s[i])){
                ans+=s[i];
                k++;
            }
            else if(s[i]==')'){
                int t = st.top();
                st.pop();
                reverse(ans.begin()+t,ans.end());
            }
            cout<<ans;
        }
        return ans;
    }
};