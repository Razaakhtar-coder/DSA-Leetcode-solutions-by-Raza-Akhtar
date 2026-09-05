class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();

        // Find longest non-decreasing suffix
        int j = n - 1;
        while (j > 0 && arr[j - 1] <= arr[j]) {
            j--;
        }

        // Already sorted
        if (j == 0) return 0;

        // Option 1: remove the entire prefix [0 ... j-1]
        int ans = j;

        // Find a non-decreasing prefix
        int i = 0;

        while (i < n && (i == 0 || arr[i - 1] <= arr[i])) {

            // Find first suffix element >= arr[i]
            while (j < n && arr[j] < arr[i]) {
                j++;
            }

            // Remove [i+1 ... j-1]
            ans = min(ans, j - i - 1);

            i++;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna