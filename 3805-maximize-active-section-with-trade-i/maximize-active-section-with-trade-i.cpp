class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int active = 0;
        for (char c : s)
            if (c == '1')
                active++;

        string t = "1" + s + "1";

        vector<pair<char, int>> blocks;

        for (char c : t) {
            if (blocks.empty() || blocks.back().first != c)
                blocks.push_back({c, 1});
            else
                blocks.back().second++;
        }

        int bestGain = 0;

        // Check every interior 1-block
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' &&
                blocks[i - 1].first == '0' &&
                blocks[i + 1].first == '0') {

                bestGain = max(bestGain,
                               blocks[i - 1].second + blocks[i + 1].second);
            }
        }

        return active + bestGain;
    }
};