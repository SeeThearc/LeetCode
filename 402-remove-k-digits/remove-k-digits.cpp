class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        for(char c:num){
            while(!st.empty() && k>0 &&st.top()>c){
                k--;
                st.pop();
            }
            st.push(c);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans="";
        int tsize = st.size();
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int i=0;
        while(ans[i]=='0'){
            i++;
        }
        return i==tsize?"0":ans.substr(i);

    }
};