class Solution {
public:
    string defangIPaddr(string address) {
        string allDefanged = ""; // take empty string to store the answer

        for (int i = 0; i < address.size(); i++) {
            if (address[i] == '.') {
                allDefanged += "[.]"; // change the string to [.]
            }
            else {
                allDefanged += address[i]; // else move forward
            }
        }

        return allDefanged;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna