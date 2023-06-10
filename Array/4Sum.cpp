class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return kSum(nums,target,0,4);
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target,int start,int k) {
        vector<vector<int>> ans;
        if(start == nums.size()) return ans;
        long long avg = target/k;
        if(nums[start] > avg || avg > nums.back()) return ans;
        if(k==2) return twoSum(nums,target,start);
        for(int i=start;i<nums.size();i++){
            if(i == start || nums[i-1] != nums[i]){
                for(vector<int>&subset: kSum(nums,static_cast<long>(target)-nums[i], i+1,k-1)){
                    ans.push_back({nums[i]});
                    ans.back().insert(end(ans.back()),begin(subset),end(subset));
                }
            }
        }
        return ans;
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start) {
        vector<vector<int>> res;
        unordered_set<long long> s;
        for (int i = start; i < nums.size(); ++i) {
            if (res.empty() || res.back()[1] != nums[i]) {
                if (s.count(target - nums[i])) {
                    res.push_back({int(target - nums[i]), nums[i]});
                }
            }
            s.insert(nums[i]);
        }                                   
        return res;
    } 
};