class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            // If mid element is greater than right,
            // min must be in right half
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } 
            // Otherwise min is in left half (including mid)
            else {
                right = mid;
            }
        }

        return nums[left];
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna