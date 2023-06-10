class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({intervals[i][0],intervals[i][1]});
        }
        sort(vec.begin(),vec.end());
        stack<pair<int,int>> st;
        st.push(vec[0]);
        for(int i=1;i<n;i++){
            pair<int,int> p = st.top();
            st.pop();
            if(p.second >= vec[i].first){
                p.second = max(p.second,vec[i].second);
                st.push(p);
            }else{
                st.push(p);
                st.push(vec[i]);
            }
        }
        while(st.size()){
            vector<int> v;
            pair<int,int> p = st.top();
            v.push_back(p.first);
            v.push_back(p.second);
            ans.push_back(v);
            st.pop();
        }
        return ans;
    }
};