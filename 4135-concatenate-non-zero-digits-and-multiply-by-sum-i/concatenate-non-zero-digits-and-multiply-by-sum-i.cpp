class Solution {
public:
    long long sumAndMultiply(int n) {
        long long ans=0;
        long long sum=0;
        while(n>0){
            int dig = n%10;
            if(dig!=0){
                ans*=10;
                ans+=dig;
                sum+=dig;
            }
            n/=10;
        }
        long long rev=0;
        while (ans > 0) {
            int digit = ans % 10;    
            rev = rev * 10 + digit; 
            ans /= 10;                 
        }

        return rev*sum;
    }
};