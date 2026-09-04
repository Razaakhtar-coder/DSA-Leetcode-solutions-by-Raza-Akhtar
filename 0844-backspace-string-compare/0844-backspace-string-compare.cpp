class Solution {
public:  //Time: O(n + m)
//Space: O(n + m)
    bool backspaceCompare(string s, string t) {
        string a = "", b = "";

        for (char c : s) {
            if (c == '#') { // if char = #
                if (!a.empty()) // and if 'a' string is not empty
                    a.pop_back();
            } else {
                a += c; // add char to 'a'
            }
        }

        for (char c : t) { 
            if (c == '#') { // if char = #
                if (!b.empty()) // and if 'b' string is not empty
                    b.pop_back();
            } else {
                b += c; // add char to 'b'
            }
        }

        return a == b;
    }
};

// class Solution { // t.c -> 0(n + m), s.c -> 0(1)
// public:
//     bool backspaceCompare(string s, string t) {
//         int i = s.size() - 1;
//         int j = t.size() - 1;

//         int skipS = 0, skipT = 0;

//         while (i >= 0 || j >= 0) {

//             // Find next valid character in s
//             while (i >= 0) {
//                 if (s[i] == '#') {
//                     skipS++;
//                     i--;
//                 } 
//                 else if (skipS > 0) {
//                     skipS--;
//                     i--;
//                 } 
//                 else {
//                     break;
//                 }
//             }

//             // Find next valid character in t
//             while (j >= 0) {
//                 if (t[j] == '#') {
//                     skipT++;
//                     j--;
//                 } 
//                 else if (skipT > 0) {
//                     skipT--;
//                     j--;
//                 } 
//                 else {
//                     break;
//                 }
//             }

//             // Compare valid characters
//             if (i >= 0 && j >= 0 && s[i] != t[j])
//                 return false;

//             // One string has a character, the other doesn't
//             if ((i >= 0) != (j >= 0))
//                 return false;

//             i--;
//             j--;
//         }

//         return true;
//     }
// };

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna