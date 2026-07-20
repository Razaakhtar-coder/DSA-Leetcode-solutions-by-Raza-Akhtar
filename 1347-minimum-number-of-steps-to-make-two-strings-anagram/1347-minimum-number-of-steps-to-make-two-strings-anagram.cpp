class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> freq(26, 0);

        for (char c : s) //t.c 0(n)   s.c 0(1)
            freq[c - 'a']++;

        int ans = 0;
        for (char c : t) {
            if (freq[c - 'a'] > 0)
                freq[c - 'a']--;
            else
                ans++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna