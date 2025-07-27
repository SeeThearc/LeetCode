class Solution {
public:
    int first(vector<int>nums,int target){
        int left=0,right=nums.size()-1,ind=-1;
        while(left<=right){
            int mid = left + (right-left) /2;
            if(nums[mid]==target){
                ind=mid;
                right=mid-1;
            }
            else if(nums[mid]>=target){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ind;
    }
    int last(vector<int>nums,int target){
        int left=0,right=nums.size()-1,ind=-1;
        while(left<=right){
            int mid = left + (right-left) /2;
            if(nums[mid]==target){
                ind=mid;
                left=mid+1;
            }
            else if(nums[mid]<=target){
                left=mid+1;
            }
            else{
                right=mid-1;
            }
        }
        return ind;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return{first(nums,target),last(nums,target)};
    }
};