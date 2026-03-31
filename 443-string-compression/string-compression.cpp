class Solution {
public:
    int compress(vector<char>& chars) {
        int index=0;
        int i=0;
        int n = chars.size();
        while(i<n){
            char curr = chars[i];
            int count=0;
            while(i<n && chars[i]==curr){
                count++;
                i++;
            }
            chars[index++]=chars[i-1];
            if(count>1){
                string cnt = to_string(count);
                for(char c:cnt){
                    chars[index++] = c;
                }
            }
        }
        return index;
    }
};