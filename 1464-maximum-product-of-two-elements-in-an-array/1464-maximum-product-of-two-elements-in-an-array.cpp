class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;

        for (int num : nums) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } 
            else if (num > max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna