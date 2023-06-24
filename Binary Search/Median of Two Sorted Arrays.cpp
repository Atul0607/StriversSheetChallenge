class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        int left=0,right=m;
        while(left<=right){
            int partitionA = (left+right)/2;
            int partitionB = (m+n+1)/2-partitionA;
            int maxleftA = (partitionA == 0) ?  INT_MIN : nums1[partitionA-1];
            int maxleftB = (partitionB == 0) ?  INT_MIN : nums2[partitionB-1];
            int minrightA = (partitionA == m) ?  INT_MAX : nums1[partitionA];
            int minrightB = (partitionB == n) ?  INT_MAX : nums2[partitionB];
            if(maxleftA <= minrightB && maxleftB<=minrightA){
                if((m+n)%2 == 0){
                    return (max(maxleftA,maxleftB)+min(minrightA,minrightB))/2.0;
                }else{
                    return max(maxleftA,maxleftB);
                }
            }else if(maxleftA > minrightB){
                right = partitionA-1;
            }else{
                left = partitionA+1;
            }
        }
        return 0.0;
    }
};