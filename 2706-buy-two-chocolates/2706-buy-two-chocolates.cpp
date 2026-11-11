class Solution {
public:
    int buyChoco(vector<int>& prices, int money) { // t.c - 0(nlogn), s.c - 0(1)
        sort(prices.begin(), prices.end());

        int cost = prices[0] + prices[1];

        if (cost <= money) {
            return money - cost;
        }

        return money;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna