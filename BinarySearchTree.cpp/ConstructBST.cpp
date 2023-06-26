//Preorder
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        if(n == 0) return NULL;
        int i=0;
        return bstfromPreorder(preorder,LONG_MIN,LONG_MAX,i,n);
    }

    TreeNode* bstfromPreorder(vector<int>& preorder,long mini,long maxi,int &i,int n){
        if(i>=n) return NULL;
        if(preorder[i]<mini || preorder[i]>maxi) return NULL;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = bstfromPreorder(preorder,mini,node->val,i,n);
        node->right = bstfromPreorder(preorder,node->val,maxi,i,n);
        return node;
    }
};