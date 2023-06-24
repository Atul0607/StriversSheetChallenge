class Solution {
public:
    vector<int> topKFrequent(vector<int>& w, int k) {
        map<int,int>mp;
        for(int i=0;i<w.size();i++){
            mp[w[i]]++;
        }
        priority_queue<pair<int, int> > p;
        // vector<pair<int,int>>res;
        for(auto it:mp){  
            p.push({it.second,it.first});
        }
        // sort(res.begin(),res.end(),cmp);
        vector<int> ans;
        while(k--){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};