class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) { // t.c- 0(n*n*n), s.c- 0(1)
        int n = arr.size();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j += 2) { // j chooses the ending index. It increases by 2 to consider odd-length subarrays only.
                for (int k = i; k <= j; k++) { // - k visits every element in the chosen subarray and adds it to sum.
                    sum += arr[k];
                }
            }
        }

        return sum;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna