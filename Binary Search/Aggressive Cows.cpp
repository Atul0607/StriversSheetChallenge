int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(),stalls.end());
    int n= stalls.size();
    if(k==2) return stalls[n-1]-stalls[0];
    int l=1,r=stalls[n-1];
    int ans=0;
    while(l<=r){
        int mid=(l+r)/2;
        int cow = 1;
        int p=1,prev=stalls[0];
        while(p<n){
            if(stalls[p]-prev>=mid){
                cow++;
                prev = stalls[p];
            }
            p++;
        }
        if(cow>=k){
            l=mid+1;
            ans=max(ans,mid);
        }else r=mid-1;
    }
    return ans;
}