class Solution {
public:
    bool hasZero(int n){
        bool zero = (to_string(n).find('0')!=-1);
        return zero;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=1;
        bool cond=false;
        while(!cond){
            if(!hasZero(a) && !hasZero(n-a)){
                cond=true;
            }
            else{
                a++;
            }
        }
        vector<int>ans = {a,n-a};
        return ans;
    }
};