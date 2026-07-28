class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
           // t.c 0(n log n)-> sorting
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = min(arr[i], arr[i - 1] + 1);
        }

        return arr.back();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna