class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0; // two largest digits
        while (n > 0) {
            int d = n % 10; // pull off the last digit
            n /= 10; // remove that digit from n
            if (d > first) {
                second = first; // old largest becomes second-largest
                first = d;  // new digit is the largest
            } else if (d > second) {
                second = d;        // not bigger than first, but bigger than second

            }
        }
        return first * second;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna