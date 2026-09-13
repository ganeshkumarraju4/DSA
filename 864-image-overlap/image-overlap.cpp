class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
       
        int max_overlap = 0;
        int n = img1.size();
        for(int dx=-(n-1);dx<n;dx++){
            for(int dy=-(n-1);dy<n;dy++){
                 int count = 0;
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int new_i = dx+i;
                        int new_j = dy+j;
                        if(new_i>=0 && new_i <n && new_j>=0 && new_j<n){
                            if (img1[i][j] == 1 && img2[new_i][new_j] == 1)
                            count++;
                        }
                    }
                }
                max_overlap = max(max_overlap,count);
            }
        }
        return max_overlap;
    }
};