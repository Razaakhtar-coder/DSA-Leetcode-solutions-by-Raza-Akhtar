class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1); //Because the maximum number of coins you'd ever need (if a 1 coin exists) is amount thats why amount + 1.
        dp[0] = 0;

        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount]; //If dp[amount] is still larger than amount, it means it was never updated, so the amount cannot be formed.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna