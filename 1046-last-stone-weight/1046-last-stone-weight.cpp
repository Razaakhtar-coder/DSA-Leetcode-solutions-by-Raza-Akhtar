class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        for (int stone : stones) {
            pq.push(stone);
        }

        while (pq.size() > 1) {  //As long as there are at least 2 stones, keep playing.
             // t.c 0(n log n)  s.c 0(n)
            int a = pq.top();  // first largest element
            pq.pop();

            int b = pq.top(); // second largest element
            pq.pop();

            if (a != b) {
                pq.push(a - b);
            }
        }

        if (pq.empty())
            return 0;

        return pq.top();
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna