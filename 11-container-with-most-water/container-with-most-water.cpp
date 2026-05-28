class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int area = 0;
        while(r > l){
            int curArea = (r - l) * min(height[l],height[r]);
            area = max(area,curArea);
            if(height[r] <= height[l])r--;
            else l++;
        }
        return area;
    }
};