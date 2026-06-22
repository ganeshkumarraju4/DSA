class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for(auto x: cardPoints){
            total += x;
        }
        int windowSize = n - k;
        if(k==0)return total;

        int windowSum = 0;
        for(int i =0;i<windowSize;i++){
            windowSum += cardPoints[i];
        }
        int minSum = windowSum;
        for(int i = windowSize;i < n;i++){
            windowSum += cardPoints[i];
            windowSum -= cardPoints[i-windowSize];
            minSum = min(minSum,windowSum);
        }
        return total - minSum;
    }
};