class Solution {
public:
    int reverse(int xx) {
        vector<int>dig;
        bool neg=false;
        long long x = xx;
        if(x<0){neg=true;x=-x;}
        while(x>0){
            int d = x%10;
            dig.push_back(d);
            x/=10;
        }
        //reverse(dig.begin(),dig.end());
        long long ans=0;
        for(int a:dig){
            ans = (ans*10)+a;
        }
        if(neg==true)ans*=-1;
        if(ans<INT_MIN || ans>INT_MAX)return 0;
        return ans;
    }
};