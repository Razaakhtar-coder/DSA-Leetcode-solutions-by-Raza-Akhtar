class Solution {
public:
    string maximumOddBinaryNumber(string s) { // t.c - 0(n), s.c - 0(n)
        int ones = count(s.begin(), s.end(), '1'); // Put all but one 1 at the beginning
        int zeros = s.size() - ones; // Put all 0s in the middle.

        string ans = "";

        ans += string(ones - 1, '1');
        ans += string(zeros, '0');
        ans += '1';

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna