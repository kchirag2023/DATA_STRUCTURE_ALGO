// Pushed: 2026-10-11 18:09:46 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 11.9 MB

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());

        string first = strs.front();
        string last = strs.back();

        string ans = "";

        int len = min(first.size(), last.size());

        for (int i = 0; i < len; i++) {
            if (first[i] != last[i])
                break;

            ans += first[i];
        }

        return ans;
    }
};