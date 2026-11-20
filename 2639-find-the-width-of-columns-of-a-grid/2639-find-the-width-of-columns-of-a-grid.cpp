class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int m = grid.size(); // t.c - 0(n*m), s.c - 0(n)
        int n = grid[0].size();

        vector<int> ans(n, 0);

        for (int j = 0; j < n; j++) {
            for (int i = 0; i < m; i++) {
                int width = to_string(grid[i][j]).size();
                ans[j] = max(ans[j], width);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna