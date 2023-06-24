class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }else if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool lc = isSameTree(p->left, q->left);
        bool rc = isSameTree(p->right, q->right);
        if(lc == false || rc == false){
            return false;
        }
        return true;
    }
};