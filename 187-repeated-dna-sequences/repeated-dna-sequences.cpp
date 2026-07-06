class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        map<string,int>mpp;
        vector<string>ans;
        for(int i=0;i<=n-10;i++){
            string temp = s.substr(i,10);
            if(mpp[temp]==1){
                ans.push_back(temp);
                mpp[temp]=2;
            }
            else if(mpp[temp]==0){
                mpp[temp]=1;
            }
        }
        return ans;
    }
};