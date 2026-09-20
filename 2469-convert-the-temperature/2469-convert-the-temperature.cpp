class Solution {
public: // t.c - 0(1), s.c - 0(1)
    vector<double> convertTemperature(double celsius) {
        vector<double> ans; // values are in decimal so take double

        double kelvin = celsius + 273.15; // calculate kelvin temperature 
        double fahrenheit = celsius * 1.80 + 32.00; // claculate fahrenheit temperature

        ans.push_back(kelvin); // push them both in ans
        ans.push_back(fahrenheit);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna