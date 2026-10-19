class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        unordered_set<int>st;
        queue<int>q;
        q.push(0);
        st.insert(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i=0;i<rooms[node].size();i++){
                if(!st.contains(rooms[node][i])){
                    st.insert(rooms[node][i]);
                    q.push(rooms[node][i]);
                }
            }
        }
        if(st.size()==n)return true;
        return false;
    }
};