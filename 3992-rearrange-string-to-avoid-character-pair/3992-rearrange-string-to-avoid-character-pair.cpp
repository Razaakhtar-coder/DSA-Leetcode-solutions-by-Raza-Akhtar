class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        string ys, mid, xs;

        for(char c : s){
            if(c == y)
                ys += c;
            else if(c == x)
                xs += c;
            else
                mid += c;
            
        }
        return ys + mid + xs;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna