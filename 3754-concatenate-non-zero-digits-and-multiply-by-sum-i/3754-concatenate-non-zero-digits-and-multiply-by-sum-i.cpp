class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        int i = 0;

        while(n > 0){
         int remainder = n % 10;
         if(remainder != 0){
            sum += remainder;
            num += pow(10, i) * remainder;
            i++;
         }
         n = n/10;
        }
        return sum*num;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna