//PostOrder and Inorder
class Solution {
public:
    map<int,int> m;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for( int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* root=func(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode *func(vector<int> &postorder, int poststart,int postend, vector<int> &inorder,int instart,int inend, map<int,int> &mp)
    {
        if(poststart>postend || instart>inend)return NULL;
        TreeNode* root=new TreeNode(postorder[postend]);
        int inroot=mp[root->val];
        int leftnum=inroot-instart;
        root->left=func(postorder,poststart,poststart+leftnum-1,inorder,instart,inroot-1,mp);
        root->right=func(postorder,poststart+leftnum,postend-1,inorder,inroot+1,inend,mp);
        return root;
    }
};

//Preorder and inorder
class Solution {
public:
    map<int,int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for( int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* root=func(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,m);
        return root;
    }
    TreeNode *func(vector<int> &preorder, int prestart,int preend, vector<int> &inorder,int instart,int inend, map<int,int> &mp)
    {
        if(prestart>preend || instart>inend)return NULL;

        TreeNode* root=new TreeNode(preorder[prestart]);
        int inroot=mp[root->val];
        int leftnum=inroot-instart;
        root->left=func(preorder,prestart+1,prestart+leftnum,inorder,instart,inroot-1,mp);
        root->right=func(preorder,prestart+leftnum+1,preend,inorder,inroot+1,inend,mp);
        return root;
    }
};