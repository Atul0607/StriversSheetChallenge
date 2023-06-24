class Solution {
public:
    vector<int> prevSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=0;i<n;i++){
            while(s.top()!=-1 && nums[s.top()] >= nums[i]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> nextSmaller(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n);
        stack<int> s;
        s.push(-1);
        for(int i=n-1;i>=0;i--){
            while(s.top()!=-1 && nums[s.top()] >= nums[i]) s.pop();
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(vector<int>& nums) {
        int n = nums.size();
        vector<int> next(n);
        next = nextSmaller(nums);
        vector<int> prev(n);
        prev = prevSmaller(nums);
        int area = INT_MIN;
        for(int i=0;i<n;i++){
            int h = nums[i];
            if(next[i] == -1) next[i]=n;
            int b = next[i]-prev[i]-1;
            int newarea = h*b;
            area = max(area,newarea);
        }
        return area;
    }
};