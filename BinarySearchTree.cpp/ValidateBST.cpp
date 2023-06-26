class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return checkinrange(root,LONG_MIN,LONG_MAX);
    }
    bool checkinrange(TreeNode* root,long mini,long maxi){
        if(root == NULL){
            return true;
        }
        if(root->val <= mini || root->val >= maxi){
            return false;
        }
        bool left = checkinrange(root->left,mini,root->val);
        bool right = checkinrange(root->right,root->val,maxi);
        return left && right;
    }
};