class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area = 0;
        int l,r;
        l = 0;r = n-1;
        int currArea = 0;
        while(l<r){
            currArea = (r-l)*min(height[l],height[r]);
            area = max(area,currArea);

            if(height[l]<=height[r])l++;
            else r--;
        }
        return area;
    }
};