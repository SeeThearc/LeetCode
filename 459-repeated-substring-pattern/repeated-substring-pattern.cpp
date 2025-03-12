class Solution {
public:
    bool repeatedSubstringPattern(string pat) {
        int n=pat.length();
        vector<int>lps(n);
        lps[0]=0;
        int i=1,j=0;
        while(i<pat.length()){
            if(pat[i]==pat[j]){
                j++;
                lps[i]=j;
                i++;
            }
            else{
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        int l=lps[n-1];
        if((l!=0) && (l%(n-l))==0){
            return true;
        }
        else{
            return false;
        }
    }
};