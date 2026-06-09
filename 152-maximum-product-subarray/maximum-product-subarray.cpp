class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = nums[0],minPro = nums[0];
        int currPro = nums[0];
        int n = nums.size();
        for(int i = 1;i <n;i++){
            int it = nums[i];
            int oldMax = maxPro;
            maxPro = max({maxPro * it,minPro * it,it});
            minPro = min({it,minPro * it,oldMax * it});
            currPro = max(maxPro,currPro);
        }
        return currPro;
    }
};