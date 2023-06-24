int Solution::findMedian(vector<vector<int> > &arr) {
    int n = arr.size();
    int m = arr[0].size();
    int k = (n*m+1)/2;
    int a = INT_MAX;
    int b = INT_MIN;
    for(int i=0;i<n;i++){
        a = min(a,arr[i][0]);
        b = max(b,arr[i][m-1]);
    }
    while(a<b){
        int mid = (a+b)/2;
        int cnt=0;
        for(int i=0;i<n;i++){
            cnt+=upper_bound(arr[i].begin(),arr[i].end(),mid)-arr[i].begin();
        }
        if(cnt<k) a=mid+1;
        else b=mid;
    }
    return a;
}
