class Solution {
public:
    string smallestSubsequence(string s) {

        // Store last occurrence of every character
        vector<int> lastIdx(26);
        vector<bool> visited(26, false);

        for (int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i;
        }

        // Create stack
        stack<char> st;

        // Traverse the string
        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            // Skip if already present
            if (visited[ch - 'a'])
                continue;

            // Remove larger characters if they appear later
            while (!st.empty() &&
                   st.top() > ch &&
                   lastIdx[st.top() - 'a'] > i) {

                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // Build answer
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna