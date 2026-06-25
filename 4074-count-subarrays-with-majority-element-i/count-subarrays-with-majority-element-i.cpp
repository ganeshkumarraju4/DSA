class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        
        int count =0;
        for(int i =0;i<n;i++){
            int len =0;
             int x = 0;
            for(int j =i;j<n;j++){
                len++;
                if(nums[j]==target)x++;
                if(x > len/2)count++;
            }
        }
        return count;
    }
};