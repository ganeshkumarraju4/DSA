class Solution {
public:

    vector<string> maxNumOfSubstrings(string s) {

        int n = s.size();

        vector<int> first(26, -1);
        vector<int> last(26, -1);

        // Find first and last occurrence
        for(int i = 0; i < n; i++) {

            int c = s[i] - 'a';

            if(first[c] == -1)
                first[c] = i;

            last[c] = i;
        }

        vector<vector<int>> intervals;

        // Construct valid intervals
        for(int c = 0; c < 26; c++) {

            if(first[c] == -1)
                continue;

            int l = first[c];
            int r = last[c];

            bool valid = true;

            for(int i = l; i <= r; i++) {

                int x = s[i] - 'a';

                // This character has an occurrence
                // before our interval starts
                if(first[x] < l) {
                    valid = false;
                    break;
                }

                // Need to include all occurrences
                // of this character
                r = max(r, last[x]);
            }

            if(valid) {
                intervals.push_back({l, r});
            }
        }

        // Earliest ending interval first
        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[1] < b[1];
            });

        vector<string> ans;

        int prevEnd = -1;

        for(auto &interval : intervals) {

            int l = interval[0];
            int r = interval[1];

            if(l > prevEnd) {

                ans.push_back(s.substr(l, r - l + 1));

                prevEnd = r;
            }
        }

        return ans;
    }
};