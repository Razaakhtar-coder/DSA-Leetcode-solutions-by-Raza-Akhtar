class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                result.pop_back();  // remove duplicate
            } else {
                result.push_back(c);  // add character
            }
        }

        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna