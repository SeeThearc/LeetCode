class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        map<int,int>mpp;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                mpp[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top()<=nums2[i]){
                    st.pop();
                }
                mpp[nums2[i]] = (st.empty())?-1:st.top();
                st.push(nums2[i]);
            }
        }
        vector<int>ans;
        int m = nums1.size();
        for(int i=0;i<m;i++){
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};