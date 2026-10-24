
class Solution {
public:
    int addDigits(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10; // get the last digit
                num /= 10; //remove the last digit
            }

            num = sum;
        }

        return num;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna