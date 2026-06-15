class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1)return intervals;
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> NOL;
        int end = intervals[0][1];
        int start = intervals[0][0];
        for(int i = 1;i < n;i++){
            int s = intervals[i][0];
            int e = intervals[i][1];
            if(s > end){
                NOL.push_back({start,end});
                start = s;
                end = e;
            }
            else if(e > end)end = e;
            
        }
        NOL.push_back({start,end});
        return NOL;
    }
};