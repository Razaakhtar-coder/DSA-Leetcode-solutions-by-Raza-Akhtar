
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();

        // Stores {element, listIndex, elementIndex}
        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        int maxElement = INT_MIN;

        // Initially point to index 0 of every list
        for (int i = 0; i < k; i++) {
            pq.push({nums[i][0], i, 0});
            maxElement = max(maxElement, nums[i][0]);
        }

        vector<int> resultRange = {-1000000, 1000000};

        while (true) {
            // Get minimum element
            auto curr = pq.top();
            pq.pop();

            int minElement = curr[0];
            int minElementListIndex = curr[1];
            int elementIdx = curr[2];

            // Update result range
            if (maxElement - minElement <
                resultRange[1] - resultRange[0]) {

                resultRange[0] = minElement;
                resultRange[1] = maxElement;
            }

            // Move to next element in the minimum element's list
            int nextIdx = elementIdx + 1;

            // Stop if this list is exhausted
            if (nextIdx >= nums[minElementListIndex].size()) {
                break;
            }

            int nextElement = nums[minElementListIndex][nextIdx];

            maxElement = max(maxElement, nextElement);

            // Insert next element into min-heap
            pq.push({
                nextElement,
                minElementListIndex,
                nextIdx
            });
        }

        return resultRange;
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna