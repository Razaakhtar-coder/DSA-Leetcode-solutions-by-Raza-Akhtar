class Solution {
public:
    string sortSentence(string s) { // TC: O(n), SC: O(n)
        vector<string> words(10);

        int i = 0;

        while (i < s.size()) {
            string word = "";

            // Get one word
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Last character is position
            int pos = word[word.size() - 1] - '0';

            // Remove position
            word.pop_back();

            words[pos - 1] = word;

            i++;
        }

        string ans = "";

        for (int i = 0; i < 10; i++) {
            if (words[i] != "") {
                if (ans != "") {
                    ans += " ";
                }

                ans += words[i];
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna