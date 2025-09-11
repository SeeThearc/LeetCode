class Solution {
public:
    bool palinrange(string s,int left,int right){
        while(left<right){
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        // stringstream ss(s);
        // char c;
        // vector<char>lett;
        // while(ss >> c){
        //     lett.push_back(c);
        // }
        int left=0,right=s.size()-1;
        while(left<right){
            if(s[left]==s[right]){
                left++;
                right--;
            }
            else{
                return palinrange(s,left+1,right) || palinrange(s,left,right-1);
            }
        }
        return true;
    }
};