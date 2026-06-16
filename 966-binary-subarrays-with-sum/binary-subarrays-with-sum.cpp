class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> m;
        int n = nums.size();
        int prefix = 0;
        m[0] = 1;
        int count = 0;
        for(auto x: nums){
            prefix += x;
            if(m.find(prefix - goal)!= m.end()){
                count+= m[prefix-goal];
            }
            m[prefix]++;
        }
        return count;
    }
};