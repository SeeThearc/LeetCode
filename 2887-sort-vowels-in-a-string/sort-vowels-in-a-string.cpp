class Solution {
public:
    string sortVowels(string s) {
        priority_queue<char,vector<char>,greater<char>>pq;
        vector<int>ind;
        int n = s.size();
        regex vowel("[aeiouAEIOU]");
        for(int i=0;i<n;i++){
            if(regex_match(string(1,s[i]),vowel)){
                pq.push(s[i]);
                ind.push_back(i);
            }
        }
        if(ind.size()==0)return s;
        int k=0,i=0;
        while(i<n && k<ind.size()){
            if(i==ind[k]){
                char ch = pq.top();
                s[i]=ch;
                k++;
                pq.pop();
            }
            i++;
        }
        return s;
    }
};