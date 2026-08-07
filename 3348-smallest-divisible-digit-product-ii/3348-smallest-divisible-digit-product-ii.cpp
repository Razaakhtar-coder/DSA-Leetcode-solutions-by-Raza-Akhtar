class Solution {
public:
    string smallestNumber(string num, long long t) {
        auto [primeCnt, ok] = getPrimeCount(t);
        if (!ok) return "-1";

        auto factorCnt = getFactorCount(primeCnt);
        if (sumValues(factorCnt) > (int)num.size())
            return construct(factorCnt);

        auto prefix = getPrimeCount(num);

        int firstZero = num.find('0');
        if (firstZero == string::npos) {
            firstZero = num.size();
            if (isSubset(primeCnt, prefix))
                return num;
        }

        for (int i = (int)num.size() - 1; i >= 0; i--) {
            int d = num[i] - '0';

            prefix = subtract(prefix, FACTOR[d]);

            int remain = num.size() - 1 - i;

            if (i > firstZero) continue;

            for (int nd = d + 1; nd <= 9; nd++) {
                auto need =
                    getFactorCount(subtract(subtract(primeCnt, prefix), FACTOR[nd]));

                if (sumValues(need) <= remain) {
                    int ones = remain - sumValues(need);
                    return num.substr(0, i) +
                           char('0' + nd) +
                           string(ones, '1') +
                           construct(need);
                }
            }
        }

        auto need = getFactorCount(primeCnt);
        return string(num.size() + 1 - sumValues(need), '1') + construct(need);
    }

private:
    const vector<unordered_map<int,int>> FACTOR = {
        {},
        {},
        {{2,1}},
        {{3,1}},
        {{2,2}},
        {{5,1}},
        {{2,1},{3,1}},
        {{7,1}},
        {{2,3}},
        {{3,2}}
    };

    pair<unordered_map<int,int>, bool> getPrimeCount(long long t) {
        unordered_map<int,int> cnt{{2,0},{3,0},{5,0},{7,0}};
        for (int p : {2,3,5,7}) {
            while (t % p == 0) {
                t /= p;
                cnt[p]++;
            }
        }
        return {cnt, t == 1};
    }

    unordered_map<int,int> getPrimeCount(const string& s) {
        unordered_map<int,int> cnt{{2,0},{3,0},{5,0},{7,0}};
        for (char c : s) {
            for (auto &[p,f] : FACTOR[c-'0'])
                cnt[p] += f;
        }
        return cnt;
    }

    unordered_map<int,int> getFactorCount(const unordered_map<int,int>& cnt) {
        unordered_map<int,int> res;

        int c8 = cnt.at(2) / 3;
        int r2 = cnt.at(2) % 3;

        int c9 = cnt.at(3) / 2;
        int c3 = cnt.at(3) % 2;

        int c4 = r2 / 2;
        int c2 = r2 % 2;

        int c6 = 0;

        if (c2 && c3) {
            c2 = 0;
            c3 = 0;
            c6 = 1;
        }

        if (c3 && c4) {
            c2 = 1;
            c6 = 1;
            c3 = 0;
            c4 = 0;
        }

        res[2] = c2;
        res[3] = c3;
        res[4] = c4;
        res[5] = cnt.at(5);
        res[6] = c6;
        res[7] = cnt.at(7);
        res[8] = c8;
        res[9] = c9;

        return res;
    }

    string construct(const unordered_map<int,int>& cnt) {
        string ans;
        for (int d = 2; d <= 9; d++)
            ans += string(cnt.at(d), char('0' + d));
        return ans;
    }

    bool isSubset(const unordered_map<int,int>& a,
                  const unordered_map<int,int>& b) {
        for (auto &[k,v] : a)
            if (b.at(k) < v) return false;
        return true;
    }

    unordered_map<int,int> subtract(unordered_map<int,int> a,
                                    const unordered_map<int,int>& b) {
        for (auto &[k,v] : b)
            a[k] = max(0, a[k] - v);
        return a;
    }

    int sumValues(const unordered_map<int,int>& mp) {
        int s = 0;
        for (auto &[_,v] : mp) s += v;
        return s;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna