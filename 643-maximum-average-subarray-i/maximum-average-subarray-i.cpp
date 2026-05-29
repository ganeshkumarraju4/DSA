class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double windowAvg = 0,maxAvg = 0;
        double windowSum = 0;
        int n = nums.size();

        for(int i = 0;i<k;i++){
            windowSum += nums[i];
        }
        windowAvg = windowSum / k;
        maxAvg = windowAvg;
        for(int i = k; i<n;i++){
            windowSum += nums[i];
            windowSum -= nums[i-k];

            windowAvg = windowSum / k;
            if(windowAvg > maxAvg)maxAvg = windowAvg;
        }
        return maxAvg;
    }
};