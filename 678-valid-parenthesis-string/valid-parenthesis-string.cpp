class Solution {
public:
    bool checkValidString(string s) {
        int leftmx = 0, leftmn = 0;
        for(auto it : s) {
            if(it == '(') {
                leftmx++;
                leftmn++;
            } else if (it == '*') {
                leftmx++;
                leftmn--;
            } else {
                leftmx--;
                leftmn--;
            }
            if(leftmx < 0) return false;
            if(leftmn < 0) leftmn = 0;
        }
        return leftmn == 0;
    }
};