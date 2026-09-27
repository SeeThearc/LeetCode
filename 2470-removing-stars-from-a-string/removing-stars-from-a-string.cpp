class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                st.push(s[i]);
            }
            else if(s[i]=='*' && !st.empty()){
                st.pop();
            }
        }
        string temp="";
        while(!st.empty()){
            temp+=st.top();
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};