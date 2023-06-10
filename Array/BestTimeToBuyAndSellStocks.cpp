class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = INT_MIN;
        int mini = prices[0];
        for(int i=0;i<prices.size();i++){
            mini = min(mini,prices[i]);
            int profit = prices[i]-mini;
            maxi = max(maxi,profit);
        }
        return maxi;
    }
};