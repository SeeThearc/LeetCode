class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        int sum=0;
        vector<int>dig;
        while(n>0){
            int d = n%10;
            if(d==0){
                n/=10;
                continue;
            }
            dig.push_back(d);
            sum+=d;
            n/=10;
        }
        reverse(dig.begin(),dig.end());
        for(int x:dig){
            ans = (ans*10)+x;
        }
        ans*=sum;
        return ans;
    }
};