class Solution {
public:
    int largestPrime(int n) {
        if(n<2)return 0;
        vector<int>pri;
        vector<bool>primes(n+1,true);
        primes[0]=primes[1]=false;
        for(int i=2;i*i<=n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j=j+i){
                    primes[j]=false;
                }
            }
        }
        for(int i=2;i<=n;i++){
            if(primes[i])pri.push_back(i);
        }
        // for(int i=0;i<pri.size();i++){
        //     cout<<pri[i];
        // }
        int i=0;
        int sum=0,ans;
        for(int x:pri){
            sum+=x;
            if(sum>n){
                break;
            }
            if(primes[sum])ans=sum;
        }
        return ans;
    }
};