int NthRoot(int n, int m) {
  // Write your code here.
  if(n==1) return m;
  int low = 1,high = m,ans=-1;
  while(low<=high){
    int mid = (high+low)/2;
    long long x = 1;
    for(int i=1;i<=n;i++){
      x*=mid;
      if(x> 1LL*m) break;
    }
    if(x == 1LL*m){
      ans = mid;
      break;
    }
    else if(x > m) high = mid-1;
    else low = mid+1;
  }
  return ans;
}