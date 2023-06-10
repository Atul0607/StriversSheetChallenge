pair<int,int> missingAndRepeating(vector<int> &nums, int n)
{
	// Write your code here 
	pair<int,int> p;
	int idx = 0;
    for(int i=0;i<nums.size();i++){
        idx = abs(nums[i]);
        if(nums[idx] < 0) break;
        nums[idx] = -1*nums[idx];
    }
	p.second = idx;
	int sum = 0;
	for(int i=0;i<nums.size();i++){
		nums[i] = abs(nums[i]);
	}
	for(int i=0;i<nums.size();i++){
		sum+=nums[i];
	}
	// cout << sum << endl;
	int r_sum = n*(n+1)/2;
	sum-=r_sum;
	p.first = idx-sum;
	return p;
	
}
