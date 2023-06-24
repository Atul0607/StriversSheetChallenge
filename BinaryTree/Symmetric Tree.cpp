class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        TreeNode* left = root->left; 
        TreeNode* right = root->right; 
        return isCorrect(left, right); 
    }
    bool isCorrect(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right; 
        }
        return left->val == right->val && isCorrect(left->left, right->right) && isCorrect(left->right, right->left); 
    }
};