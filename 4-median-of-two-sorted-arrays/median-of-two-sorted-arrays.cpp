class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int>merge;
        int i=0,j=0;
        while(i!=m && j!=n){
            if(nums1[i]<nums2[j]){
                merge.push_back(nums1[i]);
                i++;
            }
            else{
                merge.push_back(nums2[j]);
                j++;
            }
        }
        while(i!=m){
            merge.push_back(nums1[i]);
            i++;
        }
        while(j!=n){
            merge.push_back(nums2[j]);
            j++;
        }
        double median=0;
        if((m+n)%2==0){
            int half = (m+n)/2;
            median = ((double)merge[half]+(double)merge[half-1])/2;
        }
        else{
            int half = (m+n)/2;
            median = (double)merge[half];
        }
        return median;
    }
};