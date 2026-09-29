class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return true;
        vector<bool> dp(n,false);
        dp[n-1] = true;

        for(int i=n-2;i>=0;i--){
            if(i+nums[i]>=n-1){
                dp[i] = true;
            }
            else {
                for(int j=i;j<=i+nums[i];j++){
                    dp[i] = dp[i] || dp[j];
                }
            }
        }
        return dp[0];
    }
};