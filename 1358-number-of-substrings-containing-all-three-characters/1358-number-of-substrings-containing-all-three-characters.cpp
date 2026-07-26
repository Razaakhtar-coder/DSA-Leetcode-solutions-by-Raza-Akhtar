class Solution {
public:
    int numberOfSubstrings(string s) {
        int n= s.size();
        int result = 0;

        vector<int> ans(3, 0);

        int i = 0, j = 0;
        while(j < n){
            char ch = s[j]; // increase j until its invalid string
            ans[ch - 'a']++;

            while( ans[0] > 0 && ans[1] > 0 && ans[2] > 0){
                result += n-j;

                ans[s[i] - 'a']--;
                i++; // increase i until its a valid string
            }
             j++;
        }
        return result;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna