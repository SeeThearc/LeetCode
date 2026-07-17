class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int ans=0;
        for(int i=0;i<8;i+=3){
            string temp1 = startTime.substr(i,2);
            string temp2 = endTime.substr(i,2);
            int val1 = stoi(temp1);
            int val2 = stoi(temp2);
            if(i==0){
                ans+=((val2-val1)*60*60);
            }
            else if(i==3){
                ans+=((val2-val1)*60);
            }
            else if(i==6){
                ans+=((val2-val1));
            }
        }
        return ans;
    }
};