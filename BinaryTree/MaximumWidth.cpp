class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int maxi = 1;
        while(!q.empty()){
            int sz = q.size();
            int min = q.front().second;
            int first = 0;
            int last = 0;
            for(int i=0;i<sz;i++){
                auto p = q.front();
                q.pop();
                int cur = p.second-min;
                TreeNode* node = p.first;
                if(i == 0) first = cur;
                if(i == sz-1) last = cur;
                if(node->left) q.push({node->left,cur*2+1});
                if(node->right) q.push({node->right,cur*2+2});
            }
            maxi = max(maxi,last-first+1);
        }
        
        return maxi;
    }
};