class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;
        int i=0;
        auto it = mp.rbegin();
        ans.push_back(it->first);
        while(i+k<n){
            mp[nums[i]]--;
            mp[nums[i+k]]++;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            auto it = mp.rbegin();
            ans.push_back(it->first);
            i++;
        }
        return ans;
    }
};