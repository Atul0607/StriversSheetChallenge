int floorInBST(TreeNode<int> * root, int val)
{
    // Write your code here.
    if(root == NULL) return -1;
    int maxi = INT_MIN;
     while(root){
        if(root->val == val){
            maxi = val;
            break;
        }
        if(root->val > val) root=root->left;
        else {
            maxi = max(maxi,root->val);
            root = root->right;
        }
    }
    return maxi;
}

int findCeil(BinaryTreeNode<int> *root, int val){
    // Write your code here.
    if(root == NULL) return -1;
    int mini = INT_MAX;
     while(root){
        if(root->data == val){
            mini = val;
            break;
        }
        if (root->data > val) {
            mini = min(mini,root->data);
          root = root->left;
        } else {
          root = root->right;
        }
    }
    return mini==INT_MAX ? -1 : mini;
}