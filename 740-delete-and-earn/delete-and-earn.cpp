class Solution {
public:
    int solve(vector<int> &dp,vector<int> &points,int value,int maxValue){
        if(value > maxValue)return 0;

        if(dp[value]!=-1)return dp[value]; 

        int take = points[value] + solve(dp,points,value+2,maxValue);
        int not_take = solve(dp,points,value+1,maxValue);
        return dp[value] = max(take,not_take);

    }
    int deleteAndEarn(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> points(mx+1,0);

        for(int i = 0;i<nums.size();i++){
            points[nums[i]] += nums[i];
        }
        vector<int> dp(mx+1,-1);
        return solve(dp,points,0,mx);
    }
};