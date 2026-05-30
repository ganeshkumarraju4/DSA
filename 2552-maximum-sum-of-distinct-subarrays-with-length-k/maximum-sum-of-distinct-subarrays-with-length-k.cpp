class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long maxSum = 0;
        long long windowSum = 0;
        int n = nums.size();
        unordered_map<int,int> freq;
       
        for(int i = 0;i<k;i++){
            windowSum += nums[i];
            freq[nums[i]]++;
        }
        if(freq.size()==k)maxSum = max(windowSum,maxSum);
        for(int i = k;i < n;i++){
            freq[nums[i]]++;
            windowSum += nums[i];
            freq[nums[i-k]]--;
            windowSum -= nums[i-k];
            if(freq[nums[i-k]]==0)freq.erase(nums[i-k]);
            if(freq.size()==k){
                maxSum = max(windowSum,maxSum);
            }
        }
        return maxSum;
    }
};