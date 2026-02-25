class Solution {
public:
    int ones(int x,map<int,int>&va){
        if(va.find(x)!=va.end())return va[x];
        bitset<32> b(x);
        string s = b.to_string();
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')c++;
        }
        va[x]=c;
        return c;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ones(arr[i],mp)>ones(arr[j],mp) || ones(arr[i],mp)==ones(arr[j],mp) && arr[i]>arr[j]){
                    swap(arr[i],arr[j]);
                }
            }
        }
        return arr;
    }
};