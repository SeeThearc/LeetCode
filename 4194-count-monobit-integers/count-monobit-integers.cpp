class Solution {
public:
    int countMonobit(int n) {
        if(n==0)return 1;
        if(n==1)return 2;
        int ans = log2(n+1);
        cout<<ans+1;
        return ans+1;
    }
};