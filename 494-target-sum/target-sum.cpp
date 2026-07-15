class Solution {
public:
    int solve(vector<int> &nums,int target,int i,int exp){
        if(i >= nums.size()){
            return target == exp ;
        }
        //take plus
        int plus = solve(nums,target,i+1,exp+nums[i]);

        //take minus
        int minus = solve(nums,target,i+1,exp - nums[i]);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};