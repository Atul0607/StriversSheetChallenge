class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        set<int> mp;
        int count = 0;
        for(int i=0;i<n;i++){
            mp.insert(nums[i]);
        }
        for(auto i: mp){
            if(mp.find(i-1) == mp.end()){
                int curr = i;
                int streak = 1;
                while(mp.find(curr+1) != mp.end()){
                    curr++;
                    streak++;
                }
                count = max(count,streak);
            }
        }
        return count;
    }
};