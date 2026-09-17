class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n,INT_MAX);
        int l  = 0;
        int currSum = 0;
        int ans = INT_MAX;

        
        for(int r=0;r<n;r++){
            currSum += arr[r];
            while(l<r && currSum>target){
                currSum-=arr[l];
                l++;
            }
            if (r > 0) {
                minLen[r] = minLen[r - 1];
            }
            if(currSum==target){
                int currLen = r-l+1;
                if(l>0 && minLen[l-1]!=INT_MAX){
                    ans = min(ans,currLen+minLen[l-1]);
                }
                minLen[r] = min(currLen,minLen[r]);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};