class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxl = -1;
        int maxarea=INT_MIN;
        for(int i=0;i<dimensions.size();i++){
            int x = dimensions[i][0];
            int y = dimensions[i][1];
            double temp = (x*x)+(y*y);
            if(temp>maxl){
                maxl=temp;
                maxarea = x*y;
            }
            else if(temp==maxl){
                maxarea=max(maxarea,x*y);
            }
        }
        if(maxarea==INT_MIN)return -1;
        return maxarea;
    }
};