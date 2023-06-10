class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        int sum=0,max_len=0;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            sum+=A[i];
            if(sum == 0) max_len=i+1;
            if(mp.find(sum) == mp.end()) mp[sum] = i;
            else{
                max_len = max(max_len,i-mp[sum]);
            }
        }
        return max_len;
    }
};