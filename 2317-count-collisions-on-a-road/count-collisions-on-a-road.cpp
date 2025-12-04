class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if(n==1)return 0;
        int c=0;
        int i=0;
        while(i<n && directions[i]=='L')i++;
        int j=n-1;
        while(j>0 && directions[j]=='R')j--;
        for(int k=i;k<=j;k++){
            if(directions[k]!='S')c++;
        }
        return c;
    }
};