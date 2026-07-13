class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLoot(n);
        if(n==1)return nums[0];

        maxLoot[0] = nums[0];
        maxLoot[1] = nums[1];
        if(n <=2 )return max(nums[0],nums[1]);
        maxLoot[2] = max(nums[1],nums[0]+nums[2]);
        for(int i = 3;i<n;i++){
            maxLoot[i] = max(maxLoot[i-2]+nums[i],maxLoot[i-3]+nums[i]);
        }
        return max(maxLoot[n-1],maxLoot[n-2]);
    }
};