class Solution {
static int comp(pair<char,pair<int,int>>&a,pair<char,pair<int,int>>&b){
    if(a.second.first==b.second.first){
        return a.second.second<b.second.second;
    }
    return a.second.first>b.second.first;
}
public:
    string sortVowels(string s) {
        int n = s.size();
        map<char,pair<int,int>>mp;
        vector<bool>place(n,false);
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                place[i]=true;
                mp[s[i]].first++;
                mp[s[i]].second=i;
            }
        }
        vector<pair<char,pair<int,int>>>vec(mp.begin(),mp.end());
        sort(vec.begin(),vec.end(),comp);
        int p=0;
        for(int i=0;i<n;i++){
            if(place[i]){
                s[i]=vec[p].first;
                vec[p].second.first--;
                if(vec[p].second.first==0)p++;
            }
        }
        return s;
    }
};