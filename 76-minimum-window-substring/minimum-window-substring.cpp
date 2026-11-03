class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp,window;
        for(char c:t){
            mp[c]++;
        }
        int req = mp.size();
        int formed=0;
        int left=0;
        int minlen=INT_MAX;
        int start=0;
        for(int right=0;right<s.size();right++){
            char c = s[right];
            window[c]++;
            if(mp.count(c) && window[c]==mp[c]){
                formed++;
            }
            while(formed==req){
                char ch = s[left];
                window[ch]--;
                if(right-left+1<minlen){
                    minlen = right-left+1;
                    start=left;
                }
                if(mp.count(ch) && window[ch]<mp[ch]){
                    formed--;
                }
                left++;
            }
        }
        return minlen==INT_MAX?"":s.substr(start,minlen);
    }
};