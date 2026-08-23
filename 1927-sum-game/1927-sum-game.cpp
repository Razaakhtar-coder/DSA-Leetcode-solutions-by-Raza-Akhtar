class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSumCount = 0;
        int rightSumCount = 0;

        int leftQnMarkCount = 0;
        int rightQnMarkCount = 0;

        for (int i = 0; i < n; i++) {

            if (num[i] == '?') {

                if (i < n / 2) {
                    leftQnMarkCount++;
                }
                else {
                    rightQnMarkCount++;
                }

            }
            else if (i < n / 2) {

                leftSumCount += num[i] - '0';

            }
            else {

                rightSumCount += num[i] - '0';

            }
        }

        int totalQnMarks = leftQnMarkCount + rightQnMarkCount;

        if (totalQnMarks % 2 == 1) {
            return true; // Alice wins
        }

        int LEFT = 2 * leftSumCount + 9 * leftQnMarkCount;
        int RIGHT = 2 * rightSumCount + 9 * rightQnMarkCount;

        if (LEFT == RIGHT) {
            return false; // Bob wins
        }
        else {
            return true; // Alice wins
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna