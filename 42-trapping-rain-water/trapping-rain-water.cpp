class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int maxleft=0,maxright=0,left=0,right=n-1,total=0;
        while(left<right){
            if(height[left]<height[right]){
                if(maxleft<height[left]){
                    maxleft=height[left];
                }
                else{
                    total+=(maxleft-height[left]);
                }
                left++;
            }
            else{
                if(maxright<height[right]){
                    maxright=height[right];
                }
                else{
                    total+=(maxright-height[right]);
                }
                right--;
            }
        }
        return total;
    }
};