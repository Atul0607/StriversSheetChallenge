vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int> ans;
	int t = x;
	if(root == NULL) return ans;
	map<int,int> mp;
	queue<TreeNode<int>*> q;
	q.push(root);
	mp[root->data] = -1;
	while(!q.empty()){
		int sz = q.size();
		for(int i=0;i<sz;i++){
			TreeNode<int> *node = q.front();
			q.pop();

			if(node->left){
				q.push(node->left);
				mp[node->left->data] = node->data;
			}
			if(node->right){
				q.push(node->right);
				mp[node->right->data] = node->data;
			}
		}
	}
	while(mp[x]!=-1){
		ans.push_back(mp[x]);
		x = mp[x];
	}
	reverse(ans.begin(),ans.end());
	ans.push_back(t);
	return ans;
}
