class Solution {
public:
    double angleClock(int hour, int minutes) {
        double m1 = minutes * 6;
       
        double h1 = (hour * 30) % 360 + minutes * 0.5;
        // double h2 = hour * 30 + m2 * 0.5;
        double deg = abs(m1-h1);
        return min(deg,360-deg);

    }
};