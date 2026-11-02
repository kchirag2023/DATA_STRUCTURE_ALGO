// Pushed: 2026-11-02 15:01:39 UTC
// Difficulty: Medium
// Runtime: 51 ms
// Memory: 27.6 MB


class Solution {
public:
    int lcsMemo(int i, int j, const string &s1,
                const string &s2, vector<vector<int>> &dp) {

        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1]) {
            return dp[i][j] = 1 + lcsMemo(
                i - 1, j - 1, s1, s2, dp
            );
        }

        return dp[i][j] = max(
            lcsMemo(i - 1, j, s1, s2, dp),
            lcsMemo(i, j - 1, s1, s2, dp)
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );

        return lcsMemo(n, m, text1, text2, dp);
    }
};


// #include <bits/stdc++.h>
// using namespace std;

// // Helper function for top-down memoization
// int lcsMemo(int i, int j, const string &s1, const string &s2, vector<vector<int>> &dp) {
//     if (i == 0 || j == 0) return 0;
//     if (dp[i][j] != -1) return dp[i][j];
    
//     if (s1[i - 1] == s2[j - 1]) {
//         return dp[i][j] = 1 + lcsMemo(i - 1, j - 1, s1, s2, dp);
//     }
    
//     // Evaluates and memoizes both branches
//     return dp[i][j] = max(lcsMemo(i - 1, j, s1, s2, dp), lcsMemo(i, j - 1, s1, s2, dp));
// }

// string findLCS(string s1, string s2) {
//     int n = s1.length();
//     int m = s2.length();
    
//     // Step 1: Initialize DP table with -1 for memoization
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    
//     // Fill the DP table using the memoized helper function
//     lcsMemo(n, m, s1, s2, dp);
    
//     // Step 2: Backtrack from dp[n][m] to reconstruct the string
//     int len = dp[n][m];
//     string lcs(len, '$'); // Placeholder string of LCS length
    
//     int index = len - 1;
//     int i = n, j = m;
    
//     while (i > 0 && j > 0) {
//         if (s1[i - 1] == s2[j - 1]) {
//             lcs[index] = s1[i - 1];
//             index--;
//             i--;
//             j--;
//         } else if (dp[i - 1][j] > dp[i][j - 1]) {
//             i--;
//         } else {
//             j--;
//         }
//     }
    
//     return lcs;
// }

// int main() {
//     string s1 = "abcde";
//     string s2 = "bdgek";
//     cout << "LCS: " << findLCS(s1, s2) << endl;
//     return 0;
// }