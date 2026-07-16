class Solution {
public:
    bool check(vector<vector<int>> &dp,vector<int> &nums,int total,int i,int sum){
        if(sum > total-sum || i >= nums.size())return false;
        if(sum == total -sum)return true;

        if(dp[i][sum] != -1)return dp[i][sum];

        return dp[i][sum] = check(dp,nums,total,i+1,sum+nums[i]) || check(dp,nums,total,i+1,sum);
        
    }
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size(),vector<int>(total+1,-1));
        return check(dp,nums,total,0,0);
    }
};