class Solution {
public: //Time: O(n × m), Space: O(n × m) for memoization + O(n) recursion stack.
    int solve(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {
        // t is completely formed
        if (j == t.size()) // entire string is matched we got 1 ans return 1.
            return 1;

        // reached till the end of s but t is not formed return 0.
        if (i == s.size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = 0;

        // If characters match, we have two choices:
        // 1. Take s[i]
        // 2. Skip s[i]
        if (s[i] == t[j]) {
            ans = solve(i + 1, j + 1, s, t, dp) // both s and t pointer moves
                + solve(i + 1, j, s, t, dp); // skip s if dosent match
        }
        else {
            // Characters don't match, so skip s[i]
            ans = solve(i + 1, j, s, t, dp); // s = b and t = c so character can never be matched so skip.
        }

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<long long>> dp(n, vector<long long>(m, -1));

        return solve(0, 0, s, t, dp);
    }
};
// BOTTOM UP
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int n = s.size();
//         int m = t.size();

//         vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

//         // Empty t can be formed from any prefix of s in 1 way:
//         // choose nothing.
//         for (int i = 0; i <= n; i++) {
//             dp[i][0] = 1;
//         }

//         for (int i = 1; i <= n; i++) {
//             for (int j = 1; j <= m; j++) {

//                 if (s[i - 1] == t[j - 1]) {
//                     // Take s[i-1] OR skip s[i-1]
//                     dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
//                 }
//                 else {
//                     // Cannot take s[i-1], so skip it
//                     dp[i][j] = dp[i - 1][j];
//                 }
//             }
//         }

//         return dp[n][m];
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna