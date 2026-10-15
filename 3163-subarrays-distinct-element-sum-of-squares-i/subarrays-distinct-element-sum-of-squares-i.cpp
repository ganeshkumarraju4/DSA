class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int> freq;
            int count = 0;
            for(int j=i;j<n;j++){
                if(freq.count(nums[j])==0){
                    freq[nums[j]]=1;
                    count++;
                }
                sum += count*count;
            }
            
        }
        return sum;
    }
};