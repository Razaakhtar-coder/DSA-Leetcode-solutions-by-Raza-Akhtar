//T.C : O(n^3)
//S.C : O(n^3)
class Solution {
public:
    
    int n;
    int t[2][101][101]; //t[2][n+1][n+1] - 2*(n+1)*(n+1) ~n^2 * n ~ O(n^3)
    int solveForAlice(vector<int>& piles, int person, int i, int M) {
        
        if(i >= n)
            return 0;
        
        if(t[person][i][M] != -1)
            return t[person][i][M];
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1; x <= min(2*M, n-i); x++) {
            
            stones += piles[i+x-1];
            
            if(person == 1) { //Alice chance
                result = max(result, stones + solveForAlice(piles, 0, i+x, max(M, x))); // max(m->1, x->1) -> 1
            } else { //Bob chnace
                result = min(result, solveForAlice(piles, 1, i+x, max(M, x))); //ex-> max(m->2, x->1) -> 2 now 2*2(M)-> 4
            }
            
        }
        
        return t[person][i][M] = result;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        
        memset(t, -1, sizeof(t));
        
        return solveForAlice(piles, 1, 0, 1);
    }
};


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna