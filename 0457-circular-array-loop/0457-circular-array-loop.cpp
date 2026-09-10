class Solution {
public:
    int next(vector<int>& nums, int i) {
        int n = nums.size();
        return (i + (long long)nums[i] % n + n) % n; // moving from index to index by taking n steps
    }

    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            bool positive = nums[i] > 0;

            int slow = i;
            int fast = i;

            while (true) {

                // Move slow one step
                int slowNext = next(nums, slow);

                // Direction changed
                if ((nums[slowNext] > 0) != positive)
                    break;

                // Move fast one step
                int fastNext = next(nums, fast);

                if ((nums[fastNext] > 0) != positive)
                    break;

                // Move fast second step
                int fastNext2 = next(nums, fastNext);

                if ((nums[fastNext2] > 0) != positive)
                    break;

                slow = slowNext;
                fast = fastNext2;

                // Cycle found
                if (slow == fast) {

                    // One element cycle is not allowed
                    if (slow == next(nums, slow)) // if this cycle contains only one index, reject it.
                        break;

                    return true;
                }
            }
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna