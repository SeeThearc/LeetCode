class Solution {
public:
    int rever(int n){
        int sum = 0;
        while(n>0){
            int dig = n%10;
            sum = (sum*10)+dig;
            n/=10;
        }
        return sum;
    }
    int mirrorDistance(int n) {
        int rev = rever(n);
        return abs(rev-n);
    }
};