class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            int idx = abs(nums[i]);
            if(nums[idx] < 0) return idx;
            nums[idx] = -1*nums[idx];
        }
        return n;
    }
};