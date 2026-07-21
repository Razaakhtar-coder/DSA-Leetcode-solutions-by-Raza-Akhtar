#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> dirs{{1,0}, {-1,0}, {0,1}, {0,-1}};
    int n;

    bool possibleDfs(vector<vector<int>>& grid, int r, int c, int time,
                     vector<vector<bool>>& vis) {

        if (r < 0 || r >= n || c < 0 || c >= n ||
            vis[r][c] || grid[r][c] > time) {
            return false;
        }

        if (r == n - 1 && c == n - 1) {
            return true;
        }

        vis[r][c] = true;

        for (auto &ngbr : dirs) {
            int nr = r + ngbr[0];
            int nc = c + ngbr[1];

            if (possibleDfs(grid, nr, nc, time, vis)) {
                return true;
            }
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
        n = grid.size();

        int left = grid[0][0];
        int right = n * n - 1; // n square 2 - 1
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            vector<vector<bool>> vis(n, vector<bool>(n, false));

            if (possibleDfs(grid, 0, 0, mid, vis)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna