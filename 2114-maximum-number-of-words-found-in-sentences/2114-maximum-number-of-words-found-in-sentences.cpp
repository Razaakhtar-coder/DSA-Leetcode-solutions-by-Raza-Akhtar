class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxWords = 0;

        for (int i = 0; i < sentences.size(); i++) {
            int words = 1;

            for (int j = 0; j < sentences[i].size(); j++) {
                if (sentences[i][j] == ' ') { // if there is space skip it, move 'word'
                    words++;
                }
            }

            maxWords = max(maxWords, words);
        }

        return maxWords;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna