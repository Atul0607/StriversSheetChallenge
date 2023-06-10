int Solution::solve(vector<int> &A, int B) {
    map<int,int> mp;
    int x = 0,count=0;
    for(int i=0;i<A.size();i++){
        x = x^A[i];
        if(x == B) count++;
        if(mp.find(x^B) != mp.end()) count+=mp[x^B];
        mp[x]++;
    }
    return count;
}
