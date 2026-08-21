class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n, 0);
        vector<int> last(26, -1); // stores last occurrence index

        const int mod = 1e9 + 7;

        dp[0] = 2; // "" + s[0]
        last[s[0] - 'a'] = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = (2LL * dp[i - 1]) % mod;

            int prev = last[s[i] - 'a'];

            if (prev == 0) {
                // Previous occurrence was at index 0
                dp[i] = (dp[i] - 1 + mod) % mod;
            }
            else if (prev > 0) {
                // Remove duplicate subsequences
                dp[i] = (dp[i] - dp[prev - 1] + mod) % mod;
            }

            last[s[i] - 'a'] = i;
        }

        // Remove empty subsequence
        dp[n - 1] = (dp[n - 1] - 1 + mod) % mod;

        return dp[n - 1];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna