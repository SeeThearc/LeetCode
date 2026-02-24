class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int total = 1<<k;
        int allone = total-1;
        int mask=0;
        vector<int>seen(total,false);
        for(int i=0;i<n;i++){
            mask = ((mask<<1)&allone) | (s[i]-'0');
            if(i>=k-1){
                if(!seen[mask]){
                    seen[mask]=true;
                    total--;
                }
                if(total==0)return true;
            }
        }
        return false;
    }
};