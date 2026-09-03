class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int n = nums.size();
        int i = 0;
        long long subProd = 1;
        int subCount = 0;

        for (int j = 0; j < n; j++) {
            subProd *= nums[j]; // multiply eveery number by moving j

            while (subProd >= k) {
                subProd /= nums[i]; // The window is too large. Remove elements from the left until the product becomes less than k example [10, 5, 2] i=10, j=2 so 100/10=10 remove 10 by increasing i.
                i++;
            }

            subCount += j - i + 1; // window size
        }

        return subCount;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna