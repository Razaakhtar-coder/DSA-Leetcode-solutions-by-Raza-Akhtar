class Solution {
public:
    string interpret(string command) {
        int n = command.size(); // t.c - 0(n), s.c - 0(n).
        string ans = "";

        for(int i=0; i<n; i++){
            if(command[i] == 'G')
            ans += 'G';

            else if(command[i] == '(' && command[i+1] == ')'){
                ans += 'o';
                i++;
            }
            else{
                ans += "al";
                i += 3; //we processed 4 characters ( a l ), (->0, a->1, l->2, )->3, (1,2,3,..n)-> idx
            }
        }
        return ans;
        
    }
};
