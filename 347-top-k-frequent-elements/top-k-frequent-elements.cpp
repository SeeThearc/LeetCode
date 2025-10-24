class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mpp;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mpp[nums[i]]++;
        }
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
            if(pq.size()>k)pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};