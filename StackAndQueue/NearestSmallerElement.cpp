vector<int> Solution::prevSmaller(vector<int> &nums) {
    int n = nums.size();
    vector<int> ans(n);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n;i++){
        int cur = nums[i];
        while(s.top() >= cur) s.pop();
        ans[i] = s.top();
        s.push(cur);
    }
    return ans;
}
