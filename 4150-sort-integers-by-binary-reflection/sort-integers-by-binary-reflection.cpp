class Solution {
public:
    int reflect(int x){
        string s="";
        while(x>0){
            s.push_back((x&1)+'0');
            x>>=1;
        }
        int val=0;
        for(char b:s){
            val = val*2 +(b - '0');
        }
        return val;
    }
    vector<int> sortByReflection(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[&](int a,int b){
            int ra = reflect(a);
            int rb = reflect(b);
            if(ra==rb)return a<b;
            else return ra<rb;
        });
        return nums;
    }
};