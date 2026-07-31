class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 1000); // since we are finding minimum value than put 10 or 100 or 1000 or any.
        // t[i] is min number of perfect square to get i
        dp[0] = 0;

        for(int i=1; i<=n; i++){
            for(int j=1; j*j<=i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        
        return dp[n];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna