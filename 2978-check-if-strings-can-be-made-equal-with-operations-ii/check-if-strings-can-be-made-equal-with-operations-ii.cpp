class Solution {
public:
    bool checkStrings(string s1, string s2) {
        unordered_map<char,int>mpe;
        unordered_map<char,int>mpo;
        for(int i=0;i<s2.size();i++){
            if(i%2==0){
                mpe[s2[i]]++;
            }
            else mpo[s2[i]]++;
        }
        for(int i=0;i<s1.size();i++){
            if(i%2==0){
                if(mpe[s1[i]]>0){
                    mpe[s1[i]]--;
                }
                else return false;
            }
            else{
                if(mpo[s1[i]]>0){
                    mpo[s1[i]]--;
                }
                else return false;
            }
        }
        return true;
    }
};