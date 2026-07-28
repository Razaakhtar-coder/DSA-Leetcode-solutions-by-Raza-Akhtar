class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if(n == 1) return s;
        long long oddPeaks = n/2;
        long long evenPeaks = (n-1)/2;

        long long ans1 = 1LL * s + oddPeaks * (m - 1) + 1;
        long long ans2 = 1LL * s + evenPeaks * (m - 1);

        return max(ans1, ans2);
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna