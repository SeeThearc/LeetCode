class Solution {
public:
    static bool cmp(const pair<char,int>  &a, const pair<char,int>  &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        map<char,int>mpp;
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }
        vector<pair<char,int>>vec(mpp.begin(),mpp.end());
        sort(vec.begin(),vec.end(),cmp);
        string res="";
        for(auto &p:vec){
            res.append(p.second,p.first);
        }
        return res;
    }
};