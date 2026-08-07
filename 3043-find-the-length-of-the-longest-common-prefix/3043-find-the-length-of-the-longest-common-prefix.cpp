#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitLength(int num) {
        int len = 0;
        while (num > 0) {
            len++;
            num /= 10;
        }
        return len;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        int ans = 0;

        for (int num : arr1) {
            while (num > 0) {
                prefixes.insert(num);
                num /= 10;
            }
        }

        for (int num : arr2) {
            int temp = num;
            while (temp > 0) {
                if (prefixes.count(temp)) {
                    ans = max(ans, digitLength(temp));
                }
                temp /= 10;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna