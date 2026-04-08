class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        map<int,int>vis;
        int dig = cbrt(n);
        for(int i=1;i<=dig;i++){
            int a = i*i*i;
            for(int j=1;j<=dig;j++){
                int b = j*j*j;
                if(a+b<=n){
                    vis[a+b]++;
                }
                else{
                    break;
                }
            }
        }
        vector<int>ans;
        for(auto it:vis){
            if(it.second>2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};