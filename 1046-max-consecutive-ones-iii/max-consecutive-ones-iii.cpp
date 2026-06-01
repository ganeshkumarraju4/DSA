class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int freqOfOnes = 0;
        int left = 0;
        int windowSize = 0;
        int maxLen = 0;
        for(int right = 0;right < nums.size();right++){
            if(nums[right] == 1)freqOfOnes++;
            windowSize++;
            while(windowSize - freqOfOnes > k){
                if(nums[left] == 1)freqOfOnes--;
                left++;
                windowSize--;
            }
            maxLen = max(maxLen,windowSize);
        }
        return maxLen;
    }
};