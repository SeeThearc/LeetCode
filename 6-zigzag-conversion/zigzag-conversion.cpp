class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        char table[numRows][s.size()];
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
                table[i][j]='\0';
            }
        }
        int row=0,col=0;
        bool down=true;
        int idx=0;
        while(idx<s.size()){
            table[row][col]=s[idx];
            idx++;
            if(row==numRows-1)down=false;
            if(row==0)down=true;
            if(down){
                row++;
            }
            else{
                row--;
                col++;
            }
        }
        string ans="";
        for(int i=0;i<numRows;i++){
            for(int j=0;j<s.size();j++){
                if(table[i][j]!='\0'){
                    ans+=table[i][j];
                }
            }
        }
        return ans;
    }
};