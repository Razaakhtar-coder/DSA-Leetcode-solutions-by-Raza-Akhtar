class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) return;

        k = ((k % n) + n) % n; //This adjusts k to a valid value. k % n removes unnecessary full rotations. + n handles negative values.
  //% n ensures the final value is between 0 and n-1. //k = -2
// //n = 7

// (-2 % 7) = -2
// (-2 + 7) = 5
// 5 % 7 = 5
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna