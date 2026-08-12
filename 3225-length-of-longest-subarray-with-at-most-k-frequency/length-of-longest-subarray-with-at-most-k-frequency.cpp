class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int maxFreq = 0;
        int left = 0;
        int n = nums.size();
        int maxLength =0;

        for(int right = 0;right<n;right++){
            freq[nums[right]]++;
            maxFreq = max(maxFreq,freq[nums[right]]);
            
            while(freq[nums[right]]>k){
                freq[nums[left]]--;
                left++;
            }
             maxLength = max(maxLength,right-left+1);
        }
        
        return maxLength;
    }
};