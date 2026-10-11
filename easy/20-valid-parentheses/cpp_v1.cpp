// Pushed: 2026-10-11 18:15:36 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 8.9 MB

class Solution {

public:

    bool isValid(string s) {

        stack<char> st;

        for (char c : s) {

            if (c == '(' || c == '{' || c == '[') {

                st.push(c);

            } else {

                if (st.empty()) return false;

                char top = st.top();

                st.pop();

                if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {

                    return false;

                }

            }

        }

        return st.empty();

    }

};