class Solution {
public:
    static const int MOD = 1e9 + 7;

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxVal = *max_element(nums.begin(), nums.end());

        vector<vector<vector<int>>> t(
            n + 1,
            vector<vector<int>>(maxVal + 1,
                vector<int>(maxVal + 1, 0))
        );

        // Base case
        for (int first = 0; first <= maxVal; first++) {
            for (int second = 0; second <= maxVal; second++) {

                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdMatch = (first == second);

                t[n][first][second] = (bothNonEmpty && gcdMatch);
            }
        }

        // Bottom-up DP
        for (int i = n - 1; i >= 0; i--) {

            for (int first = 0; first <= maxVal; first++) {

                for (int second = 0; second <= maxVal; second++) {

                    long long skip = t[i + 1][first][second];

                    long long take1 = t[i + 1][__gcd(first, nums[i])][second];
                    long long take2 = t[i + 1][first][__gcd(second, nums[i])];

                    t[i][first][second] =
                        (skip + take1 + take2) % MOD;
                }
            }
        }

        return t[0][0][0];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna