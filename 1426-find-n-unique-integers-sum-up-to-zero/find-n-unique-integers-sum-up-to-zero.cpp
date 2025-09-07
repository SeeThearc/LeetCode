class Solution {
public:
    vector<int> sumZero(int n) {
        bool isodd=false;
        if(n%2==1){
            n=n-1;
            isodd=true;
        };
        vector<int>ls;
        for(int i=1;i<=n/2;i++){
            ls.push_back(i);
            ls.push_back(-i);
        }
        if(isodd)ls.push_back(0);
        return ls;
    }
};