class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long count = 0;
       long long int subStr = 0;
        for(char &ch : s){
            if(ch == c){ // found char
                subStr += 1 + count; // add substring and increase count of char
                count ++;
            }

        }
        return subStr; // return the substring
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna