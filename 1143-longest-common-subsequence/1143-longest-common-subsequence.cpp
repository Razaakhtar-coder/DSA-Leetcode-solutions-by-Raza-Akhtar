class Solution {
public:
    int t[1001][1001];

    int solve(string &X, string &Y, int m, int n) {
        if (m == 0 || n == 0) return 0;

        if (t[m][n] != -1) return t[m][n];

        if (X[m-1] == Y[n-1]) {
            return t[m][n] = 1 + solve(X, Y, m-1, n-1);
        }

        return t[m][n] = max(
            solve(X, Y, m-1, n),
            solve(X, Y, m, n-1)
        );
    }

    int longestCommonSubsequence(string X, string Y) {
        memset(t, -1, sizeof(t));
        return solve(X, Y, X.size(), Y.size());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna