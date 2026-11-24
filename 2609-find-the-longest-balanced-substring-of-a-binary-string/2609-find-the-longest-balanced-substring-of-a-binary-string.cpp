class Solution {
public:
    int findTheLongestBalancedSubstring(string s) { // t.c - 0(n), s.c - 0(1)
        int ans = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            int zeros = 0, ones = 0;

            while (i < n && s[i] == '0') {
                zeros++;
                i++;
            }

            while (i < n && s[i] == '1') {
                ones++;
                i++;
            }

            ans = max(ans, 2 * min(zeros, ones)); // A balanced substring needs equal numbers of zeros and ones.
            i--;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna