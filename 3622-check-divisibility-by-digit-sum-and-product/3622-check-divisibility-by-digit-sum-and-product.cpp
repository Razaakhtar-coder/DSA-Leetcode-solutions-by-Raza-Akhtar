class Solution {
public:
    bool checkDivisibility(int n) {
        int ans = n; // why storing n because later we r going to change n while extracting its digit
        int sum = 0;
        int product = 1; //We start with 1 because 1 is the multiplicative identity

        while(n != 0){
            int lastDigit = n % 10; // gives the last digit of number
            sum += lastDigit;
            product *= lastDigit;
            n = n / 10; // remove the last digit
        }
        int finalOutcome = sum + product;
        return (ans % finalOutcome) == 0; //checks whether ans is perfectly divisible by finalOutcome.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna