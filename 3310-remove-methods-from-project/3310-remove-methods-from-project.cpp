class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);  // t.c-> 0(V+E), s.c-> 0(V+E) 
        vector<int> inDegree(n, 0);
        vector<bool> suspeciousBug(n, false);

        for(auto &edge : invocations){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            inDegree[v]++;
        }

        queue<int> q;
        q.push(k);
        suspeciousBug[k] = true;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
        
        for(auto &ngbr : adj[curr]){
            inDegree[ngbr]--;
            if(!suspeciousBug[ngbr]){
                q.push(ngbr);
                suspeciousBug[ngbr] = true;
            }
        }
        }
        vector<int> result;
        bool cannotRemove = false;
        
        for(int i=0; i<n; i++){
            if(suspeciousBug[i] && inDegree[i] > 0){
                cannotRemove = true;
                break;
            }
        }
            for(int i=0; i<n; i++){
            if(!suspeciousBug[i]){
               result.push_back(i);
            }
        }

        if(cannotRemove){
        vector<int> vec(n); // 0,1,2.....n-1
        for(int i=0; i<n; i++){
           vec[i] = i;
        }
        return vec;
        }

        return result;

    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna