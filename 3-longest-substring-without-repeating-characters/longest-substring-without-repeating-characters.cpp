class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mpp;
        int n = s.size();
        int left=0,right=0;
        int ans=0;
        while(right<n){
            while(mpp[s[right]]==1){
                mpp[s[left]]=0;
                left++;
            }
            ans=max(ans,right-left+1);
            mpp[s[right]]=1;
            right++;
        }
        return ans;
    }
};