class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size();
        int n = mat[0].size();

        queue<pair<int,int>> q;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        // Put all 0s into queue
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        // Multi-source BFS
        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nx = x + dx[k];
                int ny = y + dy[k];

                // Boundary check
                if(nx >= 0 && ny >= 0 && nx < m && ny < n) {

                    // Relaxation
                    if(dist[nx][ny] > dist[x][y] + 1) {

                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna