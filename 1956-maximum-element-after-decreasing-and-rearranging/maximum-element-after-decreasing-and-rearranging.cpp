class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        if(arr.size()==1)return 1;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(arr[0]!=1)arr[0]=1;
        for(int i = 0;i<n-1;i++){
            if(abs(arr[i+1]-arr[i]) > 1)arr[i+1] = arr[i]+1;
        }
        return arr[n-1];
    }
};