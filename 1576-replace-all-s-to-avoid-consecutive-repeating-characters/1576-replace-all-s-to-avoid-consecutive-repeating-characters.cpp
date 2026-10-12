class Solution {
public:
    string modifyString(string s) { // t.c - 0(n), s.c - 0(1)
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (i > 0 && s[i - 1] == ch) { // skip char
                        continue;
                    }

                    if (i < n - 1 && s[i + 1] == ch) {
                        continue;
                    }

                    s[i] = ch;
                    break;
                }
            }
        }

        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna