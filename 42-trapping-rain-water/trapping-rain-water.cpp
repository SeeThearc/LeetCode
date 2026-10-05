class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left=0,maxleft=0,right=n-1,maxright=0;
        int total=0;
        while(left<right){
            if(height[left]<height[right]){
                if(maxleft<height[left]){
                    maxleft = height[left];
                }
                else{
                    total += (maxleft-height[left]);
                }
                left++;
            }
            else{
                if(maxright<height[right]){
                    maxright = height[right];
                }
                else{
                    total += (maxright-height[right]);
                }
                right--;
            }
        }
        return total;
    }
};