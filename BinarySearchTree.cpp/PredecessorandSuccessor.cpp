class Solution
{
    public:
    void f(Node* root, Node* &pre, Node* &suc, int key){
        if(root == NULL) return;
        if(key < root->key){
            suc = root;
            f(root->left, pre, suc, key);
        }
        if(key > root->key){
            pre = root;
            f(root->right, pre, suc, key);
        }
        if(key == root->key){
            f(root->left, pre, suc, key);
            f(root->right, pre, suc, key);
        }
    }
        
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        return f(root,pre,suc,key);
    }
};