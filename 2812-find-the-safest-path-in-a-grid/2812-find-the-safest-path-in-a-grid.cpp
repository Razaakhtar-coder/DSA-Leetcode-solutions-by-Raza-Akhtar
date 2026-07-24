class Solution {
public:
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Compute distance to nearest thief
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()) {
            auto [x,y] = q.front();
            q.pop();

            for(auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if(nx>=0 && ny>=0 && nx<n && ny<n &&
                   dist[nx][ny] > dist[x][y] + 1) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }

        int low = 0, high = 2 * n;

        auto can = [&](int safe) {
            if(dist[0][0] < safe) return false;

            queue<pair<int,int>> qq;
            vector<vector<int>> vis(n, vector<int>(n,0));

            qq.push({0,0});
            vis[0][0] = 1;

            while(!qq.empty()) {
                auto [x,y] = qq.front();
                qq.pop();

                if(x == n-1 && y == n-1)
                    return true;

                for(auto &d : dirs) {
                    int nx = x + d[0];
                    int ny = y + d[1];

                    if(nx>=0 && ny>=0 && nx<n && ny<n &&
                       !vis[nx][ny] &&
                       dist[nx][ny] >= safe) {
                        vis[nx][ny] = 1;
                        qq.push({nx,ny});
                    }
                }
            }

            return false;
        };

        while(low < high) {
            int mid = (low + high + 1) / 2;

            if(can(mid))
                low = mid;
            else
                high = mid - 1;
        }

        return low;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna