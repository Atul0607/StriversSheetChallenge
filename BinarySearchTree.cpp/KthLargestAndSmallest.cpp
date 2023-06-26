//Smallest  
class Solution {
public:
    int count = 0;
    int val;
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL){
            return 0;
        }
        int left = kthSmallest(root->left,k);
        count++;
        if(count == k){
            val = root->val;
            return val;
        }
        int right = kthSmallest(root->right,k);
        return val;
    }
};

//Largest
class Solution
{
    public:
    int f(Node* root,int &i,int k){
        if(root == NULL){
            return -1;
        }
        int right =f(root->right,i,k);
        if(right != -1) return right;
        i++;
        if(i == k){
            return root->data;
        }
        return f(root->left,i,k);
    }
    int kthLargest(Node *root, int k)
    {
        //Your code here
        int i =0;
        return f(root,i,k);
        
    }
};