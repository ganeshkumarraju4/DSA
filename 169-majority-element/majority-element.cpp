class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it: nums){
            m[it]++;
        }
        int ans = 0,count=0;
        for(auto it: m){
            if(it.second > count){
                count = it.second;
                ans = it.first;
            }
        }
        return ans;
    }
};