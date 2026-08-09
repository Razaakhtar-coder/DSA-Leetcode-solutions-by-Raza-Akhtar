class Solution {
public:
    bool isUgly(int n) {
        if(n == 0) return false;

        while(n%2 == 0){
            n = n/2;
        }
        while(n%3 == 0){
            n = n/3;
        }
        while(n%5 == 0){
            n= n/5;
        }
        return n == 1;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna