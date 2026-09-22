class Solution {
public:
    bool isSubsequence(string s, string t) { // t.c - 0(n)(t.size), s.c - 0(1)
        int i = 0;
        int j = 0;

        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) { // we found the next required character
                i++; // Regardless of whether they match, we move through t
            }
            j++;
        }

        return i == s.size(); // means every character of s was successfully found in order.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna