class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n > 0 && (n & (n-1)) == 0)
        return true;// take out the binary of every element and calculate the power, first calc. power of n and then n-1 and add n and n-1. ex-> 16-> 10000 and 15-> 01111 so ans-> 00000 so 16 is power of two
        // so if n > 0 and n & n-1 == 0 than only it will be power of two.
        else{
            return false;
        }
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna