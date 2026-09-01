class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int maxRightElement = -1; // initialize it with -1 beacuse rightmost elemnt has nothing greater so acc. to problem it should be -1

        for(int i=n-1; i>=0; i--){ // loop from backword because we want max element
            int currElement = arr[i]; // We save the current element before changing it.
            arr[i] = maxRightElement; //Now we replace the current element with the greatest element we've seen on its right.

            maxRightElement = max(maxRightElement, currElement);
        }

        return arr;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna