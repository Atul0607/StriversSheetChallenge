#include <bits/stdc++.h> 

    int maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        map<int,int> mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;
        int i=0;
        auto it = mp.begin();
        ans.push_back(it->first);
        while(i+k<n){
            mp[nums[i]]--;
            mp[nums[i+k]]++;
            if(mp[nums[i]] == 0) mp.erase(nums[i]);
            auto it = mp.begin();
            ans.push_back(it->first);
            i++;
        }
        int maxi = ans[0];
        for(int j=1;j<ans.size();j++){
            maxi = max(maxi,ans[j]);
        }
        return maxi;
    }
    vector<int> maxMinWindow(vector<int> a, int n) {
        // Write your code here.
        int i=1;
        vector<int> ans;
        while(i<=n){
            ans.push_back(maxSlidingWindow(a,i));
            i++;
        }
        return ans;
    }