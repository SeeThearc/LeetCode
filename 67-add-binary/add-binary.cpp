class Solution {
public:
    string addBinary(string a, string b) {
        string s="";
        int n = a.size();
        int m = b.size();
        int i=n-1,j=m-1;
        int c=0;
        while(i>=0 || j>=0 || c){
            int sum = c;
            if(i>=0) sum+=a[i--]-'0';
            if(j>=0) sum+=b[j--]-'0';
            s.push_back((sum%2)+'0');
            c = sum/2;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};