// Pushed: 2026-11-02 16:14:28 UTC
// Difficulty: Hard
// Runtime: 208 ms
// Memory: 13.9 MB

class Solution {
public:
//    1. What does Matrix Chain Multiplication mean?
// Suppose you have three matrices:
// - A = 10 × 20
// - B = 20 × 30
// - C = 30 × 40
// You want to multiply all three matrices:
// \[
// A \times B \times C
// \]

// The important thing is that the order of multiplication can change the number of operations, but the final result remains the same.

// For example, there are two ways:

// Option 1: (A × B) × C

// First multiply A and B:
// \[
// 10 \times 20 \times 30 = 6000
// \]

// Resulting matrix: 10 × 30.

// Now multiply with C:
// \[
// 10 \times 30 \times 40 = 12000
// \]

// Total operations:
// \[
// 6000+12000=\boxed{18000}
// \]

// Option 2: A × (B × C)

// First multiply B and C:
// \[
// 20 \times 30 \times 40 = 24000
// \]

// Resulting matrix: 20 × 40.

// Now multiply with A:
// \[
// 10 \times 20 \times 40 = 8000
// \]

// Total operations:
// \[
// 24000+8000=\boxed{32000}
// \]

// Optimal answer: 18000
// So, our objective is to find the minimum number of scalar multiplications.
    int solve(int i, int j, vector<int>& a, vector<vector<int>>& dp) {
        // Base case: if range is invalid, return 0 coins
        if (i > j) return 0;
        
        // Return if already computed
        if (dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        
        // Try making every balloon at 'index' the LAST balloon to be burst in range [i, j]
      
        for (int index = i; index <= j; index++) {
            int cost = (a[i - 1] * a[index] * a[j + 1]) + 
                       solve(i, index - 1, a, dp) + 
                       solve(index + 1, j, a, dp);
            maxi = max(maxi, cost);
        }
        
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // Add 1 at the beginning and end
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        // Initialize DP table with -1
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        
        return solve(1, n, nums, dp);
    }
};