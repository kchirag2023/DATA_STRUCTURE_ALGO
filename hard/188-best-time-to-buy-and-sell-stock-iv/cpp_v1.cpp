// Pushed: 2026-11-02 14:33:12 UTC
// Difficulty: Hard
// Runtime: 13 ms
// Memory: 17.7 MB

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int f(int ind, int tranNo, vector<int>& prices, int n, int k, vector<vector<int>>& dp) {
        // Base case: if we reach the end of the array or completed all 2*k transactions
        if (ind == n || tranNo == 2 * k) return 0;
        
        // Return already computed states
        if (dp[ind][tranNo] != -1) return dp[ind][tranNo];
        
        // Even transaction number means Buy, Odd transaction number means Sell
        if (tranNo % 2 == 0) {
            // Choice 1: Buy the stock (lose money, move to next index, increment transaction number)
            // Choice 2: Skip buying (move to next index, keep transaction number same)
            return dp[ind][tranNo] = max(-prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp),
                                           0 + f(ind + 1, tranNo, prices, n, k, dp));
        } else {
            // Choice 1: Sell the stock (gain money, move to next index, increment transaction number)
            // Choice 2: Skip selling (move to next index, keep transaction number same)
            return dp[ind][tranNo] = max(prices[ind] + f(ind + 1, tranNo + 1, prices, n, k, dp),
                                           0 + f(ind + 1, tranNo, prices, n, k, dp));
        }
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp table of size [n][2 * k] initialized to -1
        vector<vector<int>> dp(n, vector<int>(2 * k, -1));
        return f(0, 0, prices, n, k, dp);
    }
};