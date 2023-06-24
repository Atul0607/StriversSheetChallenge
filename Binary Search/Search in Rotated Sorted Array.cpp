class Solution {
public:
    int piv = 0;
    int search(vector<int>& nums, int target) {
        if(target == nums[0]) return 0;
        minElement(nums);
        int ele = -1;
        if(target>nums[0] && piv!=0){
            ele = binarySearch(0,piv-1,target,nums);
        }else{
            ele = binarySearch(piv,nums.size()-1,target,nums);
        }
        return ele;
    }

    int binarySearch(int low,int high,int x,vector<int>& nums){
        while(low<=high){
            int mid = (high+low)/2;
            if(x == nums[mid]) return mid;
            else if(x > nums[mid]) low = mid+1;
            else high = mid-1;
        }
        return -1;
    }

    int minElement(vector<int>& nums){
        int first = nums[0];
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid= (low+high)/2;
            if(nums[mid] >= first) low = mid+1;
            else{
                high = mid-1;
                piv = mid;
            }
        }
        return piv;
    }

};