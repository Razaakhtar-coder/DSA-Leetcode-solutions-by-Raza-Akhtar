class Solution {
public:
    string removeStars(string s) {
        string ans;

        for(char c : s) {
            if(c == '*') {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna