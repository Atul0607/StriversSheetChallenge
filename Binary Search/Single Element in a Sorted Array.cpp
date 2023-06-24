class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int n = nums[0];
        // for(int i=1;i<nums.size();i++){
        //     n = n xor nums[i];
        // }
        // return n;
        int n = nums.size();
        if(n==1) return nums[0];
        int low=0,high=n-1;
        while(low<high){
            int mid = (high+low)/2;
            if(mid%2==1) mid--;
            if(nums[mid] != nums[mid+1]) high = mid;
            else low = mid+2;
        }
        return nums[low];
    }
};