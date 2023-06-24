class Solution {
public:
    int height(TreeNode* node) {
		if(node == NULL) {
			return 0; //-1 for edges and 0 for nodes
		}
		int ls = height(node->left);
		int rs = height(node->right);
		int h = max(ls, rs)+1;
		return h;
	}
    bool isBalanced(TreeNode* root) {
        if(root == NULL) {
			return true; //-1 for edges and 0 for nodes
		}
		bool ls = isBalanced(root->left);
		bool rs = isBalanced(root->right);
        if(abs(height(root->left)-height(root->right)) > 1){
            return false;
        }
        if(ls == false || rs == false){
            return false;
        }
		return true;
    }
};