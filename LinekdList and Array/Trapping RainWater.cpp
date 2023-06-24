class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> nge(n);
        vector<int> nge2(n);
        nge[0] = height[0];
        for(int i=1;i<n;i++){
            nge[i] = max(nge[i-1],height[i]);
        }
        nge2[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            nge2[i] = max(nge2[i+1],height[i]);
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=min(nge[i],nge2[i])-height[i];
        }
        return sum;
    }
};