class Solution {
public:
    int maxi = INT_MIN;
    int maxPathSum(TreeNode* root) {
        findmax(root);
        return maxi;    
    }

    int findmax(TreeNode* node){
        if(node == NULL){
            return 0;
        }
        int lh = max(0,findmax(node->left));
        int rh = max(0,findmax(node->right));
        maxi = max(lh+rh+node->val,maxi);
        return max(lh,rh)+node->val;
    }
};