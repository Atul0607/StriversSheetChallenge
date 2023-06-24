vector<int> Solution::solve(vector<int> &A, vector<int> &B, int C) {
    sort(A.begin(),A.end(),greater<int>());
    sort(B.begin(),B.end(),greater<int>());
    
    priority_queue<vector<int>> pq;
    pq.push({A[0]+B[0],0,0});
    int cnt = 0;
    vector<int> ans;
    set<vector<int>> s;
    
    while(cnt<C){
        auto top = pq.top();
        pq.pop();
        int i = top[1];
        int j = top[2];
        ans.push_back(top[0]);
        
        auto p1=s.find({i+1,j});
        auto p2=s.find({i,j+1});
        if(p1 == s.end() && i+1<A.size()){
            pq.push({A[i+1]+B[j],i+1,j});
            s.insert({i+1,j});
        }
        if(p2 == s.end() && j+1<B.size()){
            pq.push({A[i]+B[j+1],i,j+1});
            s.insert({i,j+1});
        }
        cnt++;
    }
    return ans;
}
