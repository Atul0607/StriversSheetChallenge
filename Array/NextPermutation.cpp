class Solution {
public:
    void swap(vector<int>& nums,int i,int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
    void reverse(vector<int>& nums,int start){
        int i=start;
        int j=nums.size()-1;
        while(i<j){
            swap(nums,i,j);
            i++;
            j--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int bp = -1,ind = -1;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i] < nums[i+1]){
                bp = i;
                break;
            }
        }
        if(bp == -1) reverse(nums,0);
        else{
            for(int i=nums.size()-1;i>=0;i--){
                if(nums[i] > nums[bp]){
                    ind = i;
                    break;
                }
            }
            swap(nums,bp,ind);
            reverse(nums,bp+1);
        }

    }
};