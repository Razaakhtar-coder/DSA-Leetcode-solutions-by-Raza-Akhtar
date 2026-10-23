class Solution {
public:
    string frequencySort(string s) { // t.c - 0(n +klogk),where \(n\) is the string length and \(k\) is the number of distinct characters.
        int n = s.size();  // s.c - 0(n + k), including the frequency map, heap, and output string.

        unordered_map<int, int> mp;

        for(char c : s){
            mp[c]++;
        }

        priority_queue<pair<int, char>> pq; // Max heap: freq and char

        for(auto &it : mp){
            pq.push({it.second, it.first});
        }
        string ans;

        while(!pq.empty()){  // Build the result in descending frequency order
         auto[count, ch] = pq.top(); // returns the highest-priority pair without removing it. ex- count= 2 and ch= 'e'
          pq.pop();

          ans += string(count, ch); // append the string to ans
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna