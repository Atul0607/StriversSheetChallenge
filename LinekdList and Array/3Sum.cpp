class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i && nums[i] == nums[i-1]) continue;
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                }
                if(sum<=0){
                    int temp = nums[j];
                    while(j<n && nums[j]==temp) j++;
                }else{
                    int temp = nums[k];
                    while(k && nums[k] == temp) k--;
                }
            }
        }
        return ans;
    }
};