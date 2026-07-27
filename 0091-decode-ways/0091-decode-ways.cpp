class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> t(n+1); // initialize dp array

        t[n] = 1; // we have valid path at last
        for(int i=n-1; i>=0; i--){ 
            if(s[i] == '0'){
                t[i] = 0;
            }
            else{
                t[i] = t[i+1]; // we want ans of of forward thats why we are running a backword loop
            }
            if(i < n-1){ // until i is in bound
                if(s[i] == '1' || s[i] == '2' && s[i+1] <= '6'){
                    t[i] += t[i+2];
                }
            }
        }
        return t[0];  // backword loop is running so ans will be on 0th idx
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna