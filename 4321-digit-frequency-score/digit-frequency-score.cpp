class Solution {
public:
    int digitFrequencyScore(int n) {
        map<int,int>freq;
        while(n>0){
            int dig = n%10;
            freq[dig]++;
            n/=10;
        }
        int score=0;
        for(auto it:freq){
            score+=(it.first*it.second);
        }
        return score;
    }
};