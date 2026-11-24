class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        long long maxElem = *max_element(nums.begin(), nums.end());
        long long maxPossibleLcm = 1;
        for (long long x = 1; x <= maxElem; x++) {
            maxPossibleLcm = lcm(maxPossibleLcm, x);
        }
        long long cap = maxPossibleLcm * maxElem;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            long long g = nums[i];
            long long l = nums[i];

            for (int j = i; j < n; j++) {
                long long b = nums[j];
                if (prod > cap / b) break; // cannot equal g * l anymore, avoids overflow
                prod *= b;

                g = gcd(g, b);
                l = lcm(l, b);

                if (prod == g * l) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};