class Solution {
public:
    string maximumXor(string s, string t) {
        int n = s.length();
        int c0=0,c1=0;
        for(int i=0;i<n;i++){
            if(t[i]=='0')c0++;
            if(t[i]=='1')c1++;
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(c1>0){ans+="1";c1--;}
                else ans+="0";
            }
            if(s[i]=='1'){
                if(c0>0){ans+="1";c0--;}
                else ans+="0";
            }
        }
        return ans;
    }
};