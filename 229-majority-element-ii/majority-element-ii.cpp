class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int k = n/3;
        vector<int> ans;
        unordered_map<int,int> hash;
        for(auto x: nums){
            hash[x]++;
            if(hash[x] > k){
                ans.push_back(x);
                hash[x] = INT_MIN;
            }
           
        }
        return ans;
    }
};