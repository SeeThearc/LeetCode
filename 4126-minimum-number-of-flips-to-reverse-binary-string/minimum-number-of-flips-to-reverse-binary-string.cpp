class Solution {
public:
    string tobinary(int x){
        if(x==0)return "0";
        string s= "";
        while(x>0){
            s+=(x%2)+'0';
            x/=2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
    int minimumFlips(int n) {
        string s1 = tobinary(n);
        string s2 = s1;
        reverse(s2.begin(),s2.end());
        int c=0;
        for(int i=0;i<s1.size();i++){
            if(s1[i]!=s2[i])c++;
        }
        return c;
    }
};