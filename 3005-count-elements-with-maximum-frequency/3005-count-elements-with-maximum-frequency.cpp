class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) { // t.c - 0(n), s.c - 0(n)-> unordered map.
        int n = nums.size();

        unordered_map<int, int> mp;

        for(int num : nums){ // count frequency of all the elements
            mp[num]++;
        }
          int maxFreq = 0;

        for (auto it : mp) { // returns the max frequency element
            maxFreq = max(maxFreq, it.second);
        }

        int count = 0;

        for (auto it : mp) { // count elements that have max frequencies
            if (it.second == maxFreq) {
                count += it.second;
            }
        }

        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
