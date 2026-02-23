class Solution {
public:
    int fact(int dig,vector<int>&facto){
        if(dig==0)return 1;
        if(facto[dig]!=0)return facto[dig];
        int f=1;
        int d=dig;
        while(d>1){
            f*=d;
            d--;
        }
        facto[dig]=f;
        return f;
    }
    bool isDigitorialPermutation(int n) {
        vector<int>facto(10,0);
        int temp = n;
        int sum=0;
        while(temp>0){
            int dig = temp%10;
            int fac = fact(dig,facto);
            temp/=10;
            sum+=fac;
        }
        string s1 = to_string(n);
        string s2 = to_string(sum);
        if(s1.length()!=s2.length())return false;
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
};