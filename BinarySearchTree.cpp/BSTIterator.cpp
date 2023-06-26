class BSTIterator {
public:
    stack<TreeNode*> st;
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        pushall(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }

    void pushall(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
};