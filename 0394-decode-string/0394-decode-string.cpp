class Solution {
public:
    string decodeString(string s) {
        stack<int> numbs;
        stack<string> str;

        int currNumb = 0;
        string currStr = "";

        for (char ch : s) {

            if (isdigit(ch)) {
                currNumb = currNumb * 10 + (ch - '0');
            }

            else if (ch == '[') {
                numbs.push(currNumb);
                str.push(currStr);

                currNumb = 0;
                currStr = "";
            }

            else if (ch == ']') {
                int repeat = numbs.top();
                numbs.pop();

                string prevStr = str.top();
                str.pop();

                for (int i = 0; i < repeat; i++) {
                    prevStr += currStr;
                }

                currStr = prevStr;
            }

            else {
                currStr += ch;
            }
        }

        return currStr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna