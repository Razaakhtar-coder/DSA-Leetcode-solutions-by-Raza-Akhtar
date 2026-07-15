class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;

        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;  // t.c -> 0(n log n)
        int r = 1;

        for (int num : temp) {
            if (rank.find(num) == rank.end()) {
                rank[num] = r++;
            }
        }

        for (int i = 0; i < arr.size(); i++) {
            arr[i] = rank[arr[i]];
        }

        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna