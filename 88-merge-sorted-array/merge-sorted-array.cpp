class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0,r = 0;
        while(l < m && r < n){
            if(nums1[l] > nums2[r]){
                for(int i = m ;i > l;i--){
                    nums1[i] = nums1[i-1];
                }
                nums1[l] = nums2[r];
                r++;
                m++;
            }
            l++;
        }
        while (r < n) {
            nums1[l] = nums2[r];
            l++;
            r++;
        }
    }
};