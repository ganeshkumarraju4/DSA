class Solution {
public:

    void Solve(string &s, unordered_set<string> &st,
               int leftRemove, int rightRemove,
               int valid, int i, string temp) {

        if (i == s.size()) {
            if (leftRemove == 0 &&
                rightRemove == 0 &&
                valid == 0) {

                st.insert(temp);
            }
            return;
        }

        if (valid < 0) return;

        if (s[i] == '(') {

            // Remove '('
            if (leftRemove > 0) {
                Solve(s, st,
                      leftRemove - 1,
                      rightRemove,
                      valid,
                      i + 1,
                      temp);
            }

            // Keep '('
            Solve(s, st,
                  leftRemove,
                  rightRemove,
                  valid + 1,
                  i + 1,
                  temp + s[i]);
        }

        else if (s[i] == ')') {

            // Remove ')'
            if (rightRemove > 0) {
                Solve(s, st,
                      leftRemove,
                      rightRemove - 1,
                      valid,
                      i + 1,
                      temp);
            }

            // Keep ')' only if there is '(' available
            if (valid > 0) {
                Solve(s, st,
                      leftRemove,
                      rightRemove,
                      valid - 1,
                      i + 1,
                      temp + s[i]);
            }
        }

        else {
            Solve(s, st,
                  leftRemove,
                  rightRemove,
                  valid,
                  i + 1,
                  temp + s[i]);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        for (char c : s) {

            if (c == '(') {
                leftRemove++;
            }

            else if (c == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        unordered_set<string> st;

        Solve(s, st,
              leftRemove,
              rightRemove,
              0,
              0,
              "");

        return vector<string>(st.begin(), st.end());
    }
};