class Solution {
public:
    int count = 0;

    void expand(string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;        // every valid expansion = one palindrome
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            expand(s, i, i);       // odd length
            expand(s, i, i + 1);   // even length
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna