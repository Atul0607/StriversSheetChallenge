class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) {
			return 0; //-1 for edges and 0 for nodes
		}
		int ls = maxDepth(root->left);
		int rs = maxDepth(root->right);
		int h = max(ls, rs)+1;
		return h;
    }
};