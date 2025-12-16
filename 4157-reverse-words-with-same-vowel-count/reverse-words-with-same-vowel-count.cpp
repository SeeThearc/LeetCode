class Solution {
public:
    string reverseWords(string s) {
        vector<string>splits;
        stringstream ss(s);
        string token;
        while(getline(ss,token,' ')){
            transform(token.begin(),token.end(),token.begin(),::tolower);
            splits.push_back(token);
        }
        int voc=0;
        string ans="";
        for(char c:splits[0]){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                voc++;
            }
        }
        ans+=splits[0];
        for(int i=1;i<splits.size();i++){
            ans+=" ";
            int voct=0;
            for(char c:splits[i]){
                if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                    voct++;
                }
            }
            if(voc==voct){
                reverse(splits[i].begin(),splits[i].end());
            }
            ans+=splits[i];
        }
        return ans;
    }
};