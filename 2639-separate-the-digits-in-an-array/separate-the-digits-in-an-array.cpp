class Solution {
public:
    void finder(vector<int>&dig,int n){
        string s = to_string(n);
        bool found=false;
        if(s[0]=='0')found=true;
        if(found)dig.push_back(0);
        vector<int>digtemp;
        while(n>0){
            int digi = n%10;
            digtemp.push_back(digi);
            n/=10;
        }
        reverse(digtemp.begin(),digtemp.end());
        for(int x:digtemp){
            dig.push_back(x);
        }
    }
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>dig;
        for(int i=0;i<nums.size();i++){
            finder(dig,nums[i]);
        }
        return dig;
    }
};