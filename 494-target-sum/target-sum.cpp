class Solution {
public:
    int solve(vector<int> &nums,int target,vector<vector<int>> &dp,int i,int exp,int offset){
        if(i >= nums.size()){
            return target == exp;
        }
        if(dp[i][exp+offset]!= -1)return dp[i][exp+offset];

        int plus = solve(nums,target,dp,i+1,exp+nums[i],offset);

        int minus = solve(nums,target,dp,i+1,exp-nums[i],offset);

        return dp[i][exp+offset] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(2*total + 1,-1));
        return solve(nums,target,dp,0,0,total);
    }
};