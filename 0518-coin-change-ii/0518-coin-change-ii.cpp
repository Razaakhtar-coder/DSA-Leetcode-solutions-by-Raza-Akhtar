class Solution {
public:
    int change(int amount, vector<int>& coins) { 
        vector<unsigned long long> dp(amount + 1, 0); // as the constraints are 3000 of coin length and 5000 of coin[i] so we take unsigned long long
        dp[0] = 1; // amount = 0, so we find 1 way 

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }

        return (int)dp[amount];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
