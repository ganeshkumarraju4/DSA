class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> hash;
        int prefix = 0;
        int maxLen = 0;
        hash[0] = -1;
        for(int i = 0;i < nums.size();i++){
            nums[i] ? prefix += 1 : prefix -= 1;
            if(hash.find(prefix) != hash.end()){
                maxLen = max(maxLen, i - hash[prefix]);
            }
            else hash[prefix] = i;
        }
        return maxLen;
    }
};