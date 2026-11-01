class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        map<char,int>freq;
        string ans="";
        for(int i=0;i<n;i++){
            freq[s[i]]++;
            if(freq[s[i]]>n/2){
                if(n%2==0)return "";
                else if(freq[s[i]]>(n+1)/2)return "";
            }
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:freq){
            pq.push({it.second,it.first});
        }
        pair<int,char>prev = {0,'#'};
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ans+=curr.second;
            curr.first--;
            if(prev.first>0){
                pq.push(prev);
            }
            prev=curr;
        }
        return ans;
    }
};