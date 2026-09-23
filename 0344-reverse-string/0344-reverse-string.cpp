class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size(); // t.c - 0(n) and s.c - 0(1).

        int i = 0;
        int j = n - 1;

        while (i < j) {
            swap(s[i], s[j]);// swap normally.

            i++;
            j--;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
