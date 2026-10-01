class Solution {
public:
    int subtractProductAndSum(int n) { // Time: O(log n) — one iteration per digit, Space: O(1)
       int prod = 1;
       int sum = 0;

       while(n > 0){
        int digit = n % 10; // get last digit , ex - 234 -> 4

        prod *= digit; // add it to product
        sum += digit; // add sum to digit

        n /= 10; // remove last digit , ex- 234 -> 23
       }

       return prod - sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna