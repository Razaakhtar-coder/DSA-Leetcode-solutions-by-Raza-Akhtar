class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int min1 = 0, max = 0;

        // Find indices of min and max
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[min1])
                min1 = i;

            if (nums[i] > nums[max])
                max = i;
        }

        // Make minIdx the smaller index
        if (min1 > max)
            swap(min1, max);

        // Case 1: Remove both from the left
        int left = max + 1;

        // Case 2: Remove both from the right
        int right = n - min1;

        // Case 3: Remove min from left, max from right
        int both = (min1 + 1) + (n - max);

        return min({left, right, both});
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna