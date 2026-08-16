class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int rem0 = 0;
        int rem1 = 0;
        int rem2 = 0;

        // Count stones based on remainder when divided by 3
        for (int stone : stones) {
            if (stone % 3 == 0)
                rem0++;
            else if (stone % 3 == 1)
                rem1++;
            else
                rem2++;
        }

        // If number of 0-remainder stones is even
        if (rem0 % 2 == 0) {
            return rem1 > 0 && rem2 > 0;
        }

        // If number of 0-remainder stones is odd
        return abs(rem1 - rem2) > 2;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna