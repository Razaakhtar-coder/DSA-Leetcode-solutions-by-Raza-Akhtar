class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) { // t.c - 0(nlogn + mlogm), s.c - 0(1)
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int fullFill = 0;
        int i = 0, j = 0;

        while(i < g.size() && j < s.size()) {
            if(s[j] >= g[i]) {
                fullFill++;
                i++;
                j++;
            }
            else {
                j++;
            }
        }

        return fullFill;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna