class Solution {
public:
    int alternateDigitSum(int n) { // t.c - 0(n); s.c - 0(1)
        int sum = 0;
        int sign = 1;

        while (n > 0) {
            sum += sign * (n % 10); // take the number from first with +ve sign
            sign *= -1;
            n /= 10;
        }

        return -sign * sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna