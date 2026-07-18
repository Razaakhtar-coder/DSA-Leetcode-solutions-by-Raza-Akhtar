class Solution {
public:
    int findGCD(vector<int>& nums) {
    int n = nums.size();

    int minElement = *min_element(nums.begin(), nums.end());
    int maxElement = *max_element(nums.begin(), nums.end());

    return __gcd(minElement, maxElement);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna