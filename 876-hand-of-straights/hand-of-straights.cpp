class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0)return false;
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[hand[i]]++;
        }
        auto it = mpp.begin();
        while(it!=mpp.end()){
            int start = it->first;
            int count = it->second;
            if(count==0){
                it++;
                continue;
            }
            for(int i=0;i<groupSize;i++){
                if(mpp[start+i]<count)return false;
                mpp[start+i]-=count;
            }
            it++;
        }
        return true;
    }
};