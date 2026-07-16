class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<long long > prefixGcd(nums.size(),0);
        int mx = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGcd[i] = gcd(mx,nums[i]);
        }
        long long sum = 0;
        sort(prefixGcd.begin(),prefixGcd.end(),greater<long long>());
        for(int i =0;i<n/2;i++){
            sum += gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return sum;
    }
};