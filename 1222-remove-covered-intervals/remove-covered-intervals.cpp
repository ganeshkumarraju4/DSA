class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n==1)return 1;
        int s = intervals[0][0];
        int e = intervals[0][1];
        for(int i = 1;i<n;i++){
            int a = intervals[i][0];
            int b = intervals[i][1];
            if(s <= a && b <= e){
                continue;
            }
            else if(a <= s && e <= b){
                e = b;
                s=a;
            }
            else {
                ans.push_back({s,e});
                s = a;
                e = b;
            }
        }
        ans.push_back({s,e});
        return ans.size();
    }
};