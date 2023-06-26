class Solution {
public:
    set<int> hs;
    bool findTarget(TreeNode* root, int k) {
        if(root==NULL) return false;
        if(hs.find(k-root->val) != hs.end()) return true;
        hs.insert(root->val);
        return findTarget(root->left,k) || findTarget(root->right,k);
    }
};