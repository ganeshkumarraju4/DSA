class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        vector<int> tails;

        for (int x : nums) {

            int pos = lower_bound(tails.begin(), tails.end(), x)
                      - tails.begin();

            if (pos == tails.size()) {
                tails.push_back(x);
            }
            else {
                tails[pos] = x;
            }
        }

        return tails.size();
    }
};