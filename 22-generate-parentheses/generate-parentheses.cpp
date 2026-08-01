class Solution {
public:
    void dfs(int open,int close,int n,string&path,vector<string>&ans){
        if(open==n && close==n){
            ans.push_back(path);
            return;
        }
        if(open<n){
            path.push_back('(');
            dfs(open+1,close,n,path,ans);
            path.pop_back();
        }
        if(close<open){
            path.push_back(')');
            dfs(open,close+1,n,path,ans);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string path;
        dfs(0,0,n,path,ans);
        return ans;
    }
};