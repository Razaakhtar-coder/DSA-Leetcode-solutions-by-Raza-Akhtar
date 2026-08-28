class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> cnt(26, 0);

        for (char c : s)
            cnt[c - 'a']++;

        // Check whether a palindrome is possible.
        int odd = 0;
        char mid = 0;

        for (int i = 0; i < 26; i++) {
            if (cnt[i] % 2) {
                odd++;
                mid = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // Remove the middle character.
        if (n % 2)
            cnt[mid - 'a']--;

        int half = n / 2;

        /*
            First check whether target's left half can be used
            exactly.
        */
        vector<int> rem = cnt;
        bool ok = true;

        for (int i = 0; i < half; i++) {
            int x = target[i] - 'a';

            if (rem[x] < 2) {
                ok = false;
                break;
            }

            rem[x] -= 2;
        }

        if (ok) {
            string left = target.substr(0, half);

            string right = left;
            reverse(right.begin(), right.end());

            string candidate = left;

            if (n % 2)
                candidate += mid;

            candidate += right;

            if (candidate > target)
                return candidate;
        }

        /*
            Find the rightmost position where we can increase
            target[i].

            Keeping the prefix unchanged as long as possible gives
            the lexicographically smallest answer.
        */
        for (int i = half - 1; i >= 0; i--) {

            // Characters required for target[0 .. i-1].
            rem = cnt;

            bool prefixOK = true;

            for (int j = 0; j < i; j++) {
                int x = target[j] - 'a';

                if (rem[x] < 2) {
                    prefixOK = false;
                    break;
                }

                rem[x] -= 2;
            }

            if (!prefixOK)
                continue;

            // Find smallest available character > target[i].
            int x = target[i] - 'a';
            int next = -1;

            for (int c = x + 1; c < 26; c++) {
                if (rem[c] >= 2) {
                    next = c;
                    break;
                }
            }

            if (next == -1)
                continue;

            rem[next] -= 2;

            // Construct left half.
            string left = target.substr(0, i);
            left += char('a' + next);

            // Fill the rest as small as possible.
            for (int c = 0; c < 26; c++) {
                while (rem[c] >= 2) {
                    left += char('a' + c);
                    rem[c] -= 2;
                }
            }

            // Mirror.
            string ans = left;

            if (n % 2)
                ans += mid;

            reverse(left.begin(), left.end());
            ans += left;

            return ans;
        }

        return "";
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna