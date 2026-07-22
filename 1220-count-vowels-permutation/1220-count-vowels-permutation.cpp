class Solution {
public:
    int countVowelPermutation(int n) {
        const long long MOD = 1e9 + 7;

        long long a = 1, e = 1, i = 1, o = 1, u = 1;

        for (int k = 2; k <= n; k++) {
            long long na = (e + i + u) % MOD;
            long long ne = (a + i) % MOD;
            long long ni = (e + o) % MOD;
            long long no = i % MOD;
            long long nu = (i + o) % MOD;

            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;
        }

        return (a + e + i + o + u) % MOD;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna