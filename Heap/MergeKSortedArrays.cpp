#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    vector<int> ans;
    priority_queue<int,vector<int>,greater<int>> p;
    for(int i=0;i<kArrays.size();i++){
        for(int j=0;j<kArrays[i].size();j++){
            p.push(kArrays[i][j]);
        }
    }
    while(!p.empty()){
        ans.push_back(p.top());
        p.pop();
    }
    return ans;
}
