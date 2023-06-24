// Inorder
class Solution {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        vector<int> ll = inorderTraversal(root->left);
        ans.push_back(root->val);
        vector<int> rl = inorderTraversal(root->right);
        return ans;
    }
};

//Preorder
class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        ans.push_back(root->val);
        vector<int> ll = preorderTraversal(root->left);
        vector<int> rl = preorderTraversal(root->right);
        return ans;
    }
};

//Postorder
class Solution {
public:
    vector<int> ans;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return ans;
        
        vector<int> ll = postorderTraversal(root->left);
        vector<int> rl = postorderTraversal(root->right);
        ans.push_back(root->val);
        return ans;
    }
};

//Level Order
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> r;
        r.push_back(root->val);
        ans.push_back(r);
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    v.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    v.push_back(node->right->val);
                }
            }
            if(v.size() != 0) ans.push_back(v);
        }
        return ans;
    }
};

//ZigZag
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> r;
        r.push_back(root->val);
        ans.push_back(r);
        int check = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            for(int i=0;i<sz;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left){
                    q.push(node->left);
                    v.push_back(node->left->val);
                }
                if(node->right){
                    q.push(node->right);
                    v.push_back(node->right->val);
                }
            }
            if(v.size() != 0){
                if(check != 1) reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            if(check == 0) check = 1;
            else check = 0;
        }
        return ans;
    }
};

//Boundary Traversal
void traverseLeft(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left) traverseLeft(root->left,ans);
    else traverseLeft(root->right,ans);
}

void traverseLeaf(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
}

void traverseRight(TreeNode<int>* root,vector<int>& ans){
    if(root == NULL || (root->left == NULL && root->right == NULL)){
        return;
    }
    if(root->right) traverseRight(root->right,ans);
    else traverseRight(root->left,ans);
    ans.push_back(root->data);
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    traverseLeaf(root->left,ans);
    traverseLeaf(root->right,ans);
    traverseRight(root->right,ans);
    return ans;
}