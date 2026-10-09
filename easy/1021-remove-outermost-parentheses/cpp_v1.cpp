// Pushed: 2026-10-09 12:10:18 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 8.9 MB


class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0) ans += c;
                balance++;
            } else {
                balance--;
                if (balance > 0) ans += c;
            }
        }

        return ans;
    }
};