class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const long long MOD = 1e9 + 7;
        long long c2 = 0, c1 = 0;
        long long total = 0;
        for (int x : nums) {
            if (x < a) {
                total += c1 + c2;
            } else if (x <= b) {
                total += c2;
                c1++;
            } else {
                c2++;
            }
        }
        return (int)(total % MOD);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna