class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {// t.c - 0(i*j*k), s.c - 0(1)
        int count = 0; // count → counts the consistent words.

        for(int i=0; i<words.size(); i++){ // i → picks a word.
            bool good = true; // good → tells us whether the whole word is consistent.

            for(int j=0; j<words[i].size(); j++){ // j → picks a character in that word.
                bool found = false;

                for(int k=0; k<allowed.size(); k++){ // k → checks whether that character exists in allowed.
                    if(words[i][j] == allowed[k]){
                        found = true;
                    }
                }
                if(found == false){ // if no matching
                    good = false;
                }
            }
            if(good == true){ // if matches than increase the count
                count++;
            }
        }
        return count;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna