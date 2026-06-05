class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = -1;
        long long prefix = 0;
        for(int i = 0;i < nums.size();i++){
            prefix += nums[i];
            int rem = ((prefix%k)+k)%k;
            if(m.find(rem) != m.end()){
                if(abs(i - m[rem]) >= 2)return true;
            }
            else m[rem] = i;
        }
        return false;
    }
};