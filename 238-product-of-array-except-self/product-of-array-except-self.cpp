class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preProductSum(n),sufProductSum(n);
        int ProductSum = 1;
        for(int i = 0;i <= n - 1;i++){
            preProductSum[i] = ProductSum;
            ProductSum *= nums[i];
        }

        ProductSum = 1;
        for(int i = n-1;i>=0;i--){
            preProductSum[i] *= ProductSum;
            ProductSum *= nums[i];
        }
        // vector<int> ans(n);
        // for(int i = 0; i< n;i++){
        //     ans[i] = preProductSum[i] * sufProductSum[i];
        // }
        return preProductSum;
    }
};