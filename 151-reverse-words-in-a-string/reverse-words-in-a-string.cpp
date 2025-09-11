class Solution {
public:
    string reverseWords(string s) {
        vector<string>arr;
        stringstream ss(s);
        string word;
        while(ss >> word){
            arr.push_back(word);
        }
        reverse(arr.begin(),arr.end());
        string st;
        for(int i=0;i<arr.size()-1;i++){
            st+=arr[i];
            st+=" ";
        }
        st+=arr[arr.size()-1];
        return st;
    }
};