class Solution {
public:  //Time: O(n + m)
//Space: O(n + m)
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";

        for (char c : s) {
            if (c == '#') {
                if (!a.empty())
                    a.pop_back();
            } else {
                a += c;
            }
        }

        for (char c : t) {
            if (c == '#') {
                if (!b.empty())
                    b.pop_back();
            } else {
                b += c;
            }
        }

        return a == b;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna