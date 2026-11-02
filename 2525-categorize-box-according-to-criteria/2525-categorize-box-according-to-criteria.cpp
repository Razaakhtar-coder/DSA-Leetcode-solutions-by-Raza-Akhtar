
class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) { // t.c - 0(1), same s.c
        long long volume = 1LL * length * width * height; // 1LL * length * width * height ensures the multiplication uses long long, preventing integer overflow.

        bool bulky = (length >= 10000 || width >= 10000 ||
                      height >= 10000 || volume >= 1000000000); // according to the question

        bool heavy = mass >= 100; // according to the question

        if (bulky && heavy) return "Both";
        if (bulky) return "Bulky";
        if (heavy) return "Heavy";

        return "Neither";
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna