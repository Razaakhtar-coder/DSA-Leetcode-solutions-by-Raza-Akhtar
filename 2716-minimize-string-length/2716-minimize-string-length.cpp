class Solution {
public:
    int minimizedStringLength(string s) { // t.c - 0(n), s.c - 0(1)
        int n = s.size();
         unordered_set<char> st;

         for(char c : s){
            st.insert(c); //  insert characters in set
         }
         return st.size(); // set only shows distinct character so, directly return them
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna