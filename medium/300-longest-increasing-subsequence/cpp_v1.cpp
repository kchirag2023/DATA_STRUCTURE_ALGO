// Pushed: 2026-11-02 15:14:45 UTC
// Difficulty: Medium
// Runtime: 679 ms
// Memory: 296.2 MB

class Solution {
public:
    int getAns(vector<int>& arr, int n, int ind, int prev_index, vector<vector<int>>& dp) {
        // Base case: if we reach the end of the array
        if (ind == n) return 0;
        
        // Return if already computed (using coordinate shift: prev_index + 1)
        if (dp[ind][prev_index + 1] != -1) {
            return dp[ind][prev_index + 1];
        }
        
        // Option 1: Not take the current element
        int notTake = 0 + getAns(arr, n, ind + 1, prev_index, dp);
        
        // Option 2: Take the current element (valid only if it's greater than the previous included element)
        int take = 0;
        if (prev_index == -1 || arr[ind] > arr[prev_index]) {
            take = 1 + getAns(arr, n, ind + 1, ind, dp);
        }
        
        // Store in the DP table and return the maximum of both choices
        return dp[ind][prev_index + 1] = max(notTake, take);
    }
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
        // DP table of size n * (n + 1) initialized to -1
        // (n + 1) columns accommodate prev_index ranging from -1 to n-1 via a +1 coordinate shift
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(arr, n, 0, -1, dp);
        
    }
};