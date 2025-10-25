class Solution {
public:
    int totalMoney(int n) {
        int mon=0;
        int tot=0;
        for(int i=0;i<n;i++){
            if(i%7==0){
                mon++;
                tot+=mon;
            }
            else{
                tot+=(mon+(i%7));
            }
        }
        return tot;
    }
};