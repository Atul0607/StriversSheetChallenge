class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        if(n == 1){
            res.push_back({1});
        }else if(n == 2){
            res.push_back({1});
            res.push_back({1,1});
        }else{
            res.push_back({1});
            res.push_back({1,1});
            for(int i=2;i<n;i++){
                vector<int> dp = res[i-1];
                vector<int> vec;
                vec.push_back(1);
                for(int j=0;j<dp.size()-1;j++){
                    vec.push_back(dp[j]+dp[j+1]);
                }
                vec.push_back(1);
                res.push_back(vec);
            }
        }
        return res;
    }
};