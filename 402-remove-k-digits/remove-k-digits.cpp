class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int>st;
        for(char c:num){
            while(!st.empty() && k>0 &&st.top()>c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        string ans="";
        while(k>0){
            st.pop();
            k--;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int tsize=ans.size();
        int t=0;
        while(ans[t]=='0')t++;
        return (t==tsize)?"0":ans.substr(t);
    }
};