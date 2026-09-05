class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int n = nums.size();
        vector<int> small(n,0);
        int smallest = nums[n-1];

        for(int i=n-1;i>=0;i--){
            if(nums[i]<smallest){
                smallest = nums[i];
            }
            small[i] = smallest;
        }
        
        int largest = nums[0];
        int score = INT_MAX;
        int index = -1;

        for(int i=0;i<=n-1;i++){
            if(nums[i]>largest)largest=nums[i];
            if(largest-small[i]<score){
                score = largest-small[i];
            }
            if(score<=k){
                index = i;
                break;
            }
        }
        return index == INT_MAX ? -1:index;
    }
};