class Solution {
public:
    int maxi = INT_MIN;
    int diameterOfBinaryTree(TreeNode* root) {
        findmax(root);
        return maxi;
    }
    int findmax(TreeNode* node) {
		if(node == NULL) {
			return 0;
		}
		int lh = findmax(node->left);
		int rh = findmax(node->right);
		maxi = max(maxi, rh+lh);
		return 1+max(lh, rh);
	}
};