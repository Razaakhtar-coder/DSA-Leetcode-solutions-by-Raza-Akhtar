
class Solution {
public:
    int countDigits(int num) { // t.c - 0(log n), s.c - 0(1)
        int originalNum = num;
        int count = 0;

        while (num > 0) {
            int digit = num % 10; // get the last digit

            if (originalNum % digit == 0) {
                count++;
            }

            num /= 10; // removes the last digit
        }

        return count;
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna