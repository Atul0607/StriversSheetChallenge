class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int a=0,b=0;
        vector<int> temp;
        for(int i=0;i<m;i++){
            temp.push_back(nums1[i]);
        }
        for(int i=0;i<m+n;i++){
            if(a!=m && b!=n){
                if(temp[a] <= nums2[b]){
                    nums1[i] = temp[a];
                    a++;
                }
                else{
                    nums1[i] = nums2[b];
                    b++;
                }
            }else if(a == m){
                nums1[i] = nums2[b];
                b++;
            }else{
                nums1[i] = temp[a];
                a++;
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};