class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> output;
        int pos = 0,neg = 0;
        int n = nums.size();
        while(pos < n && neg < n){
            while(nums[pos]<0)pos++;
            while(nums[neg]>0)neg++;
            output.push_back(nums[pos]);
            pos++;
            output.push_back(nums[neg]);
            neg++;
        }
        while(pos < n && nums[pos] <0)pos++;
        if(pos<n)output.push_back(nums[pos]);
        while(neg < n && nums[neg]>0)neg++;
        if(neg<n)output.push_back(nums[neg]);

        return output;
    }
};