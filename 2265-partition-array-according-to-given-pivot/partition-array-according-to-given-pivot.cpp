class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>lower,equal,upper;
        for(int x:nums){
            if(x<pivot){
                lower.push_back(x);
            }
            else if(x==pivot){
                equal.push_back(x);
            }
            else{
                upper.push_back(x);
            }
        }
        for(int x:equal){
            lower.push_back(x);
        }
        for(int x:upper){
            lower.push_back(x);
        }
        return lower;
    }
};