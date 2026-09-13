class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        reverse(s.begin(), s.end());

        string ans = "";
        for(int i = 0; i < n; i++) {

            if(s[i] == ' ') continue;

            string word = "";

            while(i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if(ans.length() > 0)
                ans += " ";

            ans += word;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna