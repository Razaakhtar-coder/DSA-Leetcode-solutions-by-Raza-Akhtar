class Solution {
public:
    string smallestSubsequence(string s) {

        // Store last occurrence of every character
        vector<int> lastIdx(26);
        vector<bool> visited(26, false); // mark char visited after they are inserted in ans

        for (int i = 0; i < s.size(); i++) {
            lastIdx[s[i] - 'a'] = i; // we get last index of every character ex-> lastIdx['a'] = 2,lastIdx['b'] = 6,lastIdx['c'] =7 lastIdx['d'] = 4
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
                   st.top() > ch && // d > c
                   lastIdx[st.top() - 'a'] > i) { // if the char does appear after in string, remove it or add it lexicograph wise

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

        reverse(ans.begin(), ans.end()); // ans comes in descending order of lexicograph so reverse it

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna