class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;

        while(n > 0){
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna