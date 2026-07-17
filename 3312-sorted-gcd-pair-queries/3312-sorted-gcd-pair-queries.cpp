// Approach: For each i, count pairs whose gcd is a multiple of i, then sweep downward subtracting
// multiples to get exact-gcd counts; prefix sum them and binary search each query's rank.
// Time: O(n + m log m + q log m) | Space: O(m)   (m = max value)

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1);
        for (int x : nums)
            freq[x]++;

        vector<long long> gcdCnt(mx + 1);

        for (int g = mx; g >= 1; g--) {
            long long cnt = 0;

            for (int m = g; m <= mx; m += g) {
                cnt += freq[m];
                gcdCnt[g] -= gcdCnt[m];
            }

            gcdCnt[g] += cnt * (cnt - 1) / 2;
        }

        for (int i = 1; i <= mx; i++)
            gcdCnt[i] += gcdCnt[i - 1];

        vector<int> ans;

        for (long long q : queries) {
            ans.push_back(
                upper_bound(gcdCnt.begin(), gcdCnt.end(), q) - gcdCnt.begin()
            );
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna