class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0,right=n-1;
        int maxarea = INT_MIN;
        while(left<right){
            int area = min(height[left],height[right])*(right-left);
            maxarea = max(maxarea,area);
            if(height[left]<height[right])left++;
            else right--;
        }
        return maxarea;
    }
};