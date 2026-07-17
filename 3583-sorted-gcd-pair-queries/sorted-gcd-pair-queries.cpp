class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = how many times x appears
        vector<long long> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // cnt[d] = numbers divisible by d
        vector<long long> cnt(mx + 1, 0);

        for (int d = 1; d <= mx; d++) {
            for (int multiple = d; multiple <= mx; multiple += d) {
                cnt[d] += freq[multiple];
            }
        }

        // gcdCount[d] = number of pairs whose gcd is exactly d
        vector<long long> gcdCount(mx + 1, 0);

        for (int d = mx; d >= 1; d--) {

            // total pairs divisible by d
            gcdCount[d] = cnt[d] * (cnt[d] - 1) / 2;

            // remove pairs whose gcd is a multiple of d
            for (int multiple = 2 * d; multiple <= mx; multiple += d) {
                gcdCount[d] -= gcdCount[multiple];
            }
        }

        // prefix[i] = total pairs having gcd <= i
        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + gcdCount[i];
        }

        vector<int> ans;

        for (long long q : queries) {

            // first gcd value whose prefix > q
            int gcdValue = lower_bound(prefix.begin() + 1,
                                       prefix.end(),
                                       q + 1) - prefix.begin();

            ans.push_back(gcdValue);
        }

        return ans;
    }
};