#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int first = nums[i]; // the first number
            int second = target - first; // sibtract target and first to get second

            if (mp.find(second) != mp.end()) {
                return {mp[second], i}; // store in hashmap
            }

            mp[first] = i; // insert
        }

        return {}; // return
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
