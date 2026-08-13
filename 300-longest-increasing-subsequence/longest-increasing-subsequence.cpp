class Solution {
public:
    int Solve( vector<vector<int>> &dp,vector<int>& nums,int prevIndex, int i) {
        if (i >= nums.size()) {
           
            return 0;
        }
        if(dp[i][prevIndex+1]!=-1)return dp[i][prevIndex+1];
        int take = 0;
        
        if (prevIndex == -1 || nums[i] > nums[prevIndex]) {
            take = 1 + Solve(dp, nums, i, i + 1);
        }

        int skip = Solve(dp,nums,prevIndex,i+1);
       return dp[i][prevIndex+1] = max(take,skip);
    }

    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));

       
        return Solve(dp, nums, -1, 0);
    }
};