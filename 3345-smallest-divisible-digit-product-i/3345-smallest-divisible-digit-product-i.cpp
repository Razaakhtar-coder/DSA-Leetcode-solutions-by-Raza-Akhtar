class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n; ; i++){  // since there is no range take i=n.
            int product = 1;
            int num = i;

            while(num > 0){
                product *= num % 10;
                num /= 10;
            }
            if(product % t == 0){
                return i;
            }

        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna