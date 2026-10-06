class Solution {
public:
    int minRotations(string s) {
        int ans=0;
        char ini='0';
        for(char c:s){
            int v = abs(c-ini);
            cout<<v;
            ans+=min(v,10-v);
            ini=c;
            cout<<ans<<" ";
        }
        return ans;
    }
};