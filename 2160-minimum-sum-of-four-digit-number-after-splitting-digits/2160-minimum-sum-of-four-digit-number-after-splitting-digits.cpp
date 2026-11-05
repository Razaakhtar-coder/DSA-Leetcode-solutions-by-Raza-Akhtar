
class Solution {
public:
    int minimumSum(int num) { // t.c - 0(1) and same s.c.
        vector<int> digits;

        while (num > 0) {
            digits.push_back(num % 10); // extract all digit
            num /= 10;
        }

        sort(digits.begin(), digits.end());

        int num1 = digits[0] * 10 + digits[2];
        int num2 = digits[1] * 10 + digits[3];

        return num1 + num2;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
