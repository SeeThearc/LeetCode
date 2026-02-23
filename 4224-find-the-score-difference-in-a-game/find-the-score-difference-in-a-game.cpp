class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        int n = nums.size();
        int score1=0,score2=0;
        bool act1=true,act2=false;
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                act1=!act1;
                act2=!act2;
            }
            if(i%6==5){
                act1=!act1;
                act2=!act2;
            }
            if(act1)score1+=nums[i];
            if(act2)score2+=nums[i];
            //cout<<"round"<<i<<" "<<score1<<" "<<score2<<endl;
        }
        return score1-score2;
    }
};