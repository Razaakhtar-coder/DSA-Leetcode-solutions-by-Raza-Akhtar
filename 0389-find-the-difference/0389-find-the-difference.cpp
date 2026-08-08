class Solution {
public:
    char findTheDifference(string s, string t) {
        int res = 0;

        for(int nums: s){
            res ^= nums;
        }
        for(int nums: t){
            res ^= nums;
        }
        return res;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna