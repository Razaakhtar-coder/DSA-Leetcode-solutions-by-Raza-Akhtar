class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<int> ans(m), last(m, -1);

        // last[j] = the latest index in word1 that can match word2[j]
        int i = n - 1, j = m - 1;
        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                --j;
            }
            --i;
        }

        bool usedChange = false;
        j = 0;

        for (i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                ans[j++] = i;
            } 
            else if (!usedChange &&
                     (j == m - 1 || i < last[j + 1])) {
                // Use the one allowed modification here.
                usedChange = true;
                ans[j++] = i;
            }
        }

        return (j == m) ? ans : vector<int>{};
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna