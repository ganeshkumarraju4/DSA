class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> points(mx+1,0);
        for (int num : nums)
            points[num] += num;

        vector<int> dp(mx + 3, 0);

        for (int value = mx; value >= 1; value--) {
            int take = points[value] + dp[value + 2];
            int skip = dp[value + 1];
            dp[value] = max(take, skip);
        }

        return dp[1];
    }   
};