class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int p1 = nums[n-1] * nums[n-2] * nums[n-3]; // multiplying last, second last ad third last largest element after sorting
        int p2 = nums[0] * nums[1] * nums[n-1]; // multiplying element at idx 0 and 1 because it may have -ve elemens after sorting and product of -ve is positive ex-> {-10, -9, 2, 4} -> -10*-9*4-> 360. i.e max number.

        return max(p1, p2); // return max of p1 and p2.
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna