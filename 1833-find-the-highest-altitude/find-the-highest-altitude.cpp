class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int alti=0;
        int ini=0;
        for(int i=0;i<n;i++){
            alti = max(alti,gain[i]+ini);
            ini = gain[i]+ini;
        }
        return alti;
    }
};