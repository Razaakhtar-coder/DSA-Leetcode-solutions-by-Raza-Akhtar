class Solution {
public:
    int lengthOfLongestSubstring(string s) {
  unordered_map<char, int> lastele;
   //our hashmap has only order of 256 chars do s.c->0(1) and t.c->0(n) 
  int left = 0; int maxLength = 0;
  
   for (int right = 0; right < s.size(); right++) {
     char c = s[right];
      // If character seen before and inside current window
   if (lastele.find(c) != lastele.end() && lastele[c] >= left) 
   { left = lastele[c] + 1; }

   lastele[c] = right;
    maxLength = max(maxLength, right - left + 1); } 
    return maxLength;
     }
      };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna