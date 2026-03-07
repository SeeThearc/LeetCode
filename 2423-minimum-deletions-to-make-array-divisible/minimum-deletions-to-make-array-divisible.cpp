class Solution {
public:
    int gcd(int a,int b){
        if(b==0)return a;
        return gcd(b,a%b);
    };
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n1 = nums.size();
        int n2 = numsDivide.size();
        sort(nums.begin(),nums.end());
        int res=numsDivide[0];
        for(int i=1;i<n2;i++){
            int a = res>numsDivide[i]?gcd(res,numsDivide[i]):gcd(numsDivide[i],res);
            res=a;
        }
        int c=0;
        cout<<res;
        for(int i=0;i<n1;i++){
            if(res%nums[i]!=0){
                c++;
            }
            else break;
        }
        return c==n1?-1:c;
    }
};