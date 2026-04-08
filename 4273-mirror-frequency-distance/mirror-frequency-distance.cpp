class Solution {
public:
    int mirrorFrequency(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        map<char,bool>vis;
        int sum=0;
        for(char c:s){
            char mirr;
            if(c>='0' && c<='9'){
                mirr = ((9-(c-'0'))+'0');
            }
            else{
                mirr = ((25 - (c-'a'))+'a');
            }
            if(!vis[c] && !vis[mirr]){
                sum+=abs(mp[c]-mp[mirr]);
                vis[c]=true;
                vis[mirr]=true;
            }
        }
        return sum;
    }
};