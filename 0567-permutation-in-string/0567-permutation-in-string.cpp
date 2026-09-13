class Solution {
public:
    bool isFreqSame(int freq1[], int freq2[]) {
        for(int i = 0; i < 26; i++) {
            if(freq1[i] != freq2[i]) // if the freq 1 not equal to freq 2, false
                return false;
        }
        return true;
    } 

    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) // if the length of the s is greater , false
            return false;

        int freq1[26] = {0};
        int freq2[26] = {0};

        for(int i = 0; i < s1.length(); i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }

        if(isFreqSame(freq1, freq2))
            return true;

        for(int i = s1.length(); i < s2.length(); i++) {
            freq2[s2[i] - 'a']++;  // add new char
            freq2[s2[i - s1.length()] - 'a']--;  // remove old char

            if(isFreqSame(freq1, freq2))
                return true;
        }

        return false;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna
