class Solution {
public:
    int largestAltitude(vector<int>& gain) { // t.c- 0(n), s.c- 0(1)
        int altitude = 0; // start with 0
        int highest = 0; // the highest altitude seen so far.

        for(int i=0; i<gain.size(); i++){
            altitude = altitude + gain[i]; // update the current altitude.

            if(altitude > highest){ // If the current altitude is greater than highest, update it.
                highest = altitude;  
            }
        }
        return highest;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna