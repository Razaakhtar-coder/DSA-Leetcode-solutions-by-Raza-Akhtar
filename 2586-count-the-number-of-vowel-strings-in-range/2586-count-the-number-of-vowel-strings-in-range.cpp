class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) { // t.c - 0(n), s.c - 0(1)
        int vowelCount = 0;
        string vowels = "aeiou"; // vowels words

        for (int i = left; i <= right; i++) {
            if (vowels.find(words[i][0]) != string::npos && // front char
                vowels.find(words[i].back()) != string::npos) { // back char
                vowelCount++;
            }
        }

        return vowelCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna