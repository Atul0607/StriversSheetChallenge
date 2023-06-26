class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        if(!node) return;
        if(node->left || node->right)
        {
               Node* temp;
               if(node->left) temp=node->left;
               else temp=NULL;
               if(node->right) node->left=node->right;
               else node->left=NULL;
               node->right=temp;
        }
        mirror(node->left);
        mirror(node->right);
    }
};