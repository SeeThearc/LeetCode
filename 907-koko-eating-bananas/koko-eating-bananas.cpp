class Solution {
public:
    bool caneatall(vector<int>&piles,int h,int k){
        long long hours=0;
        for(int pile:piles){
            hours+=ceil((double)pile/k);
        }
        return hours<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1,ans=-1;
        int right = *max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid = left+(right-left)/2;
            if(caneatall(piles,h,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};