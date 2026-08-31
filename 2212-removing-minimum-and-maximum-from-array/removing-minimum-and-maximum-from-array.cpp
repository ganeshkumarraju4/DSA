class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0;
        int maxi = 0;
        int n= nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<nums[mini])
            mini = i;
            if(nums[i]>nums[maxi])
            maxi = i;
        }
        int ans = n;
        int min_index = 0;
        int max_index = 0;
        min_index = min(mini,maxi);
        max_index = max(mini,maxi);
        if(min_index == max_index){
            return min(min_index+1,n-min_index);
        }
        else {
            
            ans = min(ans,max_index+1);//both left side
            ans = min(ans,n-min_index);//both right
            ans = min(ans,min_index+1 + n-max_index);//opposite side

        }
        return ans;
    }
};