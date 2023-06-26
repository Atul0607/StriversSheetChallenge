class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) return root;
        root->next = NULL;
        queue<Node*> q;
        q.push(root);
        while(q.size()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == sz-1) node->next = NULL;
                else node->next = q.front();
            }
        }
        return root;
    }
};