class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int altitude = 0;
        int temp = 0;
        for(auto x: gain){
            temp += x;
            altitude = max(altitude,temp);
        }
        return altitude;
    }
};