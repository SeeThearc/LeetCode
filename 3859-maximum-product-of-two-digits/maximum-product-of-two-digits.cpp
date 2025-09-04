class Solution {
public:
    int maxProduct(int n) {
        int temp = n;
        vector<int>digits;
        int max1=INT_MIN;
        while(temp){
            int dig = temp%10;
            digits.push_back(dig);
            temp/=10;
        }
        int max2=INT_MIN;
        int oi;
        sort(digits.begin(),digits.end(),greater<int>());
        if(digits[0]>=0)max1=digits[0];
        if(digits[1]>=0)max2=digits[1];
        int ans=1;
        if(max1!=INT_MIN){
            ans*=max1;
        }
        if(max2!=INT_MIN){
            ans*=max2;
        }
        return ans;
    }
};