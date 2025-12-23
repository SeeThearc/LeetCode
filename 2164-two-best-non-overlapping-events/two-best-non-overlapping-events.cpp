class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int>suff(n);
        suff[n-1]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1],events[i][2]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,events[i][2]);
            int low = i+1;
            int high = n-1;
            int idx=-1;
            while(low<=high){
                int mid = (low+high)/2;
                if(events[mid][0]>=events[i][1]+1){
                    idx = mid;
                    high = mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            if(idx!=-1){
                ans = max(ans,events[i][2]+suff[idx]);
            }
        }
        return ans;
    }
};