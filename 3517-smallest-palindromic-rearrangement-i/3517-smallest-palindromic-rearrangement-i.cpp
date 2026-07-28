class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

       int mid = n/2; // mid comes in middles element
        sort(s.begin(), s.begin() + mid); //sort the first half elements

        for(int i=0; i<mid; i++){
            s[n-1-i] = s[i]; // assign current char of string in the right half of the string accordingly lexico wise.
        }

        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna