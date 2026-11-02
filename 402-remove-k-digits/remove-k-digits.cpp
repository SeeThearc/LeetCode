class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && k>0 && num[i]<st.top()){
                k--;
                st.pop();
            }
            st.push(num[i]);
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int tsize=ans.size();
        int t=0;
        while(t<tsize && ans[t]=='0'){
            t++;
        }
        return t==tsize?"0":ans.substr(t);
    }
};