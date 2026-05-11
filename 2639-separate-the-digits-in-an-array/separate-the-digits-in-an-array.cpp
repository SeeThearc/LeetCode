class Solution {
public:
    void finder(vector<int>&dig,int n){
        string s = to_string(n);
        for(int i=0;i<s.size();i++){
            dig.push_back(s[i]-'0');
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