class Solution {
public:
    int helper(int i,string s,int sign,long long num){
        if(i>s.size() || !isdigit(s[i]))return (int)(sign*num);
        num = num*10 + (s[i]-'0');
        if(sign*num <= INT_MIN)return INT_MIN;
        if(sign*num >=INT_MAX)return INT_MAX;
        return helper(i+1,s,sign,num);
    }
    int myAtoi(string s) {
        int i=0;
        while(i<s.size() && s[i]==' ')i++;
        int sign=1;
        if(i<s.size() && (s[i]=='+' || s[i]=='-')){
            sign = s[i]=='-'?-1:1;
            i++;
        }
        return helper(i,s,sign,0);
    }
};