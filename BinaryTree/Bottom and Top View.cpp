class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        if(root == NULL) return ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto it = q.front();
                q.pop();
                Node* node = it.first;
                int pos = it.second;
                mp[pos] = node->data;
                // if(mp.find(pos) == mp.end()) mp[pos] = node->data; top view
                if(node->left) q.push({node->left,pos-1});
                if(node->right) q.push({node->right,pos+1});
            }
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};