class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long cost=0;
        long long c=1;
        long long MOD = 1000000007;
        long long INV2 = 500000004;
        int kt=k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(k>=nums[i]){
                k-=nums[i];
            }
            else{
                // while(k<nums[i]){
                //     k+=kt;
                //     cost+=c;
                //     c++;
                // }
                int count = (nums[i]-k+kt-1)/kt;
                long long sum = (count % MOD)*((2*(c%MOD)+(count-1)%MOD)%MOD)%MOD;
                sum = (sum*INV2)%MOD;
                cost+=sum;
                k+=(count*kt);
                c+=count;
                k-=nums[i];
            }
        }
        return cost % 1000000007;
    }
};