class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> points(mx+1,0);
        for (int num : nums)
            points[num] += num;

        int prev1 = 0;
        int prev2 = 0;
        int curr = 0;
        for (int value = mx; value >= 1; value--) {
            curr = max(points[value]+prev2,prev1);

            prev2 = prev1;
            prev1 = curr;
        }

        return curr;
    }   
};