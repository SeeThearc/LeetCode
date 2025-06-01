class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int bill5=0,bill10=0,bill20=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                bill5+=1;
            }
            else if(bills[i]==10){
                bill10+=1;
                if(bill5==0){
                    return false;
                }
                else{
                    bill5-=1;
                }
            }
            else if(bills[i]==20){
                bill20+=1;
                if(bill10>0 && bill5>0){
                    bill10-=1;
                    bill5-=1;
                }
                else if(bill5>2){
                    bill5-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};