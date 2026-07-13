class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        int curr = 0;
        for(int i = 2;i<n-1;i++){
            curr = max(prev1+nums[i] , prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        int maxi1 = max(prev2,prev1);
        prev1 = nums[1];
        prev2 = max(nums[1],nums[2]);
         for(int i = 3;i<n;i++){
            curr = max(prev1+nums[i] , prev2);
            prev1 = prev2;
            prev2 = curr;
        }
        int maxi2 = max(prev1,prev2);
        return max(maxi1,maxi2);
    }
};