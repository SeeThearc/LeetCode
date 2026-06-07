class Solution {
public:
    bool consecutiveSetBits(int n) {
        string bits="";
        while(n>0){
            bits+=n%2 + '0';
            n/=2;
        }
        reverse(bits.begin(),bits.end());
        bool found=false;
        cout<<bits;
        for(int i=1;i<bits.size();i++){
            if(bits[i]==bits[i-1] && bits[i]=='1'){
                if(!found){
                    found =true;
                }
                else{
                    return false;
                }
            }
        }
        if(found)return true;
        return false;
    }
};