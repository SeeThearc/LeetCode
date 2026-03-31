class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,bool>mp;
        int n = s.size();
        int left=0,right=0;
        int maxi=0;
        while(right<n){
            if(!mp[s[right]]){
                mp[s[right]]=true;
                maxi=max(maxi,right-left+1);
                right++;
            }
            else{
                mp[s[left]]=false;
                left++;
            }
        }
        return maxi;
    }
};