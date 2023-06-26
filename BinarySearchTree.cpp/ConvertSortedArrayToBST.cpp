class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return NULL;
        return bstfromInorder(nums,0,n-1);
    }

    TreeNode* bstfromInorder(vector<int>& nums,int st,int end){
        if(st > end) return NULL; 
        int mid = (st+end)/2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = bstfromInorder(nums,st,mid-1);
        node->right = bstfromInorder(nums,mid+1,end);
        return node;
    }
};