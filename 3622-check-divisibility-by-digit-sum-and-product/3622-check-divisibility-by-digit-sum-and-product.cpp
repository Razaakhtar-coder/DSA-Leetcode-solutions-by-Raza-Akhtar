class Solution {
public:
    bool checkDivisibility(int n) {
        int ans = n;
        int sum = 0;
        int product = 1;

        while(n != 0){
            int lastDigit = n % 10;
            sum += lastDigit;
            product *= lastDigit;
            n = n / 10;
        }
        int finalOutcome = sum + product;
        return (ans % finalOutcome) == 0;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna