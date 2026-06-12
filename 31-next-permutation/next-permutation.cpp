class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return;
        int pivot = n-1;
        while(pivot > 0 && nums[pivot-1] >= nums[pivot])pivot--;
        if(pivot == 0){
            sort(nums.begin(),nums.end());
            return;
        }
        
        int j = n - 1;
        while(nums[j] <= nums[pivot - 1]) j--;
        swap(nums[pivot - 1], nums[j]);

        reverse(nums.begin() + pivot, nums.end());

    }
};