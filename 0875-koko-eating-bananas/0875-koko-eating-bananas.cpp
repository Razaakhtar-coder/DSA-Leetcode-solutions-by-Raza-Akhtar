class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;   // ceil(pile / k)
        }

        return hours <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid)) {
                right = mid;      // try smaller speed
            } else {
                left = mid + 1;   // need larger speed
            }
        }

        return left;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna