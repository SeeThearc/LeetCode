class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int>st;
        int ind=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(asteroids[i]>=0){
                st.push(asteroids[i]);
            }
            else{
                int curr = abs(asteroids[i]);
                while(!st.empty() && st.top()<curr){
                    st.pop();
                }
                if(st.empty()){
                    ans.push_back(asteroids[i]);
                }
                else if(st.top()==curr){
                    st.pop();
                }
            }
        }
        vector<int>m;
        while(!st.empty()){
            m.push_back(st.top());
            st.pop();
        }
        reverse(m.begin(),m.end());
        for(int x:m)ans.push_back(x);
        return ans;
    }
};