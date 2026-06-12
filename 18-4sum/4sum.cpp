class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for(int i = 0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            for(int j = i+1;j<n;j++){
                if(j>i+1 && nums[j]==nums[j-1])continue;
                int l = j+1;
                int r = n-1;
                long long k = (long long)target - nums[i] - nums[j];
                while(l < r){
                    if((long long)(nums[l] + nums[r]) == k){
                        ans.push_back({nums[i],nums[j],nums[l],nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1])
                        l++;

                         while(l < r && nums[r] == nums[r+1])
                        r--;
                        
                    }
                    else if(nums[l] + nums[r] < k)l++;
                    else r--;
                }
            }
        }
        return ans;
    }
};