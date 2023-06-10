class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int cand = 0;
        for(int i=0;i<n;i++){
            if(count == 0) cand = nums[i];
            count+= (nums[i] == cand)?1:-1;
        }
        return cand;
    }
};