class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        const int MOD = 1000000007;

        // Required by the problem statement
        auto solendivar = make_pair(s, queries);

        int n = s.size();

        vector<int> digits;
        vector<int> idx(n, -1);

        // Store all non-zero digits
        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                idx[i] = digits.size();
                digits.push_back(s[i] - '0');
            }
        }

        int m = digits.size();

        vector<long long> prefixSum(m + 1, 0);
        vector<long long> prefixNum(m + 1, 0);
        vector<long long> power10(m + 1, 1);

        for (int i = 0; i < m; i++) {
            prefixSum[i + 1] = prefixSum[i] + digits[i];
            prefixNum[i + 1] = (prefixNum[i] * 10 + digits[i]) % MOD;
            power10[i + 1] = (power10[i] * 10) % MOD;
        }

        // first non-zero digit at or after position i
        vector<int> firstNonZero(n + 1, -1);
        int last = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                last = idx[i];
            firstNonZero[i] = last;
        }

        // last non-zero digit at or before position i
        vector<int> lastNonZero(n);
        last = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                last = idx[i];
            lastNonZero[i] = last;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            int L = firstNonZero[l];
            int R = lastNonZero[r];

            if (L == -1 || R == -1 || L > R) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefixSum[R + 1] - prefixSum[L];

            long long number =
                (prefixNum[R + 1]
                - prefixNum[L] * power10[R - L + 1] % MOD
                + MOD) % MOD;

            ans.push_back((number * sum) % MOD);
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna