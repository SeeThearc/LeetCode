class Solution {
public:
    string largestGoodInteger(string num) {
        int count=0;
        int maxi=INT_MIN;
        for(int i=1;i<num.size();i++){
            if(num[i]==num[i-1]){
                count++;
                if(count==2){
                    maxi=max(maxi,(int)num[i]);
                }  
            }
            else{
                count=0;
            }
        }
        if(maxi==INT_MIN)return "";
        return string(3,maxi);
    }
};