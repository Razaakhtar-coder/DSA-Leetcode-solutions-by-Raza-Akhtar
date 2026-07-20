class Solution {
public:
    char repeatedCharacter(string s) {
        vector<bool> seen(26, false);

        for (char c : s) {  // t.c 0(n)   s.c 0(1)
            if (seen[c - 'a'])
                return c;
            seen[c - 'a'] = true;
        }

        return ' '; // This line is never reached as per problem constraints.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna