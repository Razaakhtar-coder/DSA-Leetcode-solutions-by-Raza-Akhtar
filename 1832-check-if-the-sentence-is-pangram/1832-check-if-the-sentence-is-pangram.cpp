class Solution {
public:
    bool checkIfPangram(string sentence) { // Tc: O(n), s.c - 0(1).
        int n = sentence.size();
        bool seen[26] = {false};

        for(int i=0; i<n; i++){
            int index = sentence[i] - 'a'; // Mark each letter we find as true, ex - 'c' - 'a' = 2 so seen[2] = true
            seen[index] = true;
        }
        for(int i=0; i<26; i++){
            if(seen[i] == false){ // Check whether any letter is missing
                return false;
            }
        }
        return true;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
