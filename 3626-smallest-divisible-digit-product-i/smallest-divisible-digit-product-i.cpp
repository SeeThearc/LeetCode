class Solution {
public:
    int pro(int n){
        int p=1;
        while(n>0){
            int dig = n%10;
            p*=dig;
            n/=10;
        }
        return p;
    }
    int smallestNumber(int n, int t) {
        for(int i=n;i<=n+t;i++){
            int p = pro(i);
            if(p%t==0)return i;
        }
        return -1;
    }
};