class Solution {
public:
    int sumOfPrimesInRange(int n) {
        string s = to_string(n);
        reverse(s.begin(),s.end());
        int rev = stoi(s);
        int low = min(n,rev);
        int high = max(n,rev);
        vector<bool>pri(high+1,true);
        pri[0]=pri[1]=false;
        for(int i=2;i*i<=high;i++){
            if(pri[i]){
                for(int j=i*i;j<=high;j+=i){
                    pri[j]=false;
                }
            }
        }
        int sum=0;
        for(int i=low;i<=high;i++){
            if(pri[i]){
                sum+=i;
            }
        }
        return sum;
    }
};