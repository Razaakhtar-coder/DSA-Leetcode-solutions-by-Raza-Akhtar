class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_map<string, function<int(int, int)>> mp = {
            {"+", [](int a, int b) { return a + b; }},
            {"-", [](int a, int b) { return a - b; }},
            {"*", [](int a, int b) { return a * b; }},
            {"/", [](int a, int b) { return a / b; }}
        };

        for (string& token : tokens) {
            if (mp.count(token)) {  //t.c -> 0(n) s.c -> 0(n)
                int b = st.top();
                 st.pop();
                int a = st.top();
                 st.pop();

                st.push(mp[token](a, b));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna