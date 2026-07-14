class Solution {
public:
    static const int MOD = 1e9 + 7;

    int dp[205][205][205];

    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if (idx == nums.size()) {
            return (g1 != 0 && g1 == g2);
        }

        int &ans = dp[idx][g1][g2];
        if (ans != -1) return ans;

        long long res = 0;

        // Skip
        res += solve(idx + 1, g1, g2, nums);

        // Put in seq1
        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        res += solve(idx + 1, ng1, g2, nums);

        // Put in seq2
        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        res += solve(idx + 1, g1, ng2, nums);

        return ans = res % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, nums);
    }
};