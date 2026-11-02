// Pushed: 2026-11-02 15:40:18 UTC
// Difficulty: Medium
// Runtime: 75 ms
// Memory: 14.6 MB


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1);
        vector<int> parent(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {

                if (nums[i] > nums[prev] &&
                    1 + dp[prev] > dp[i]) {

                    dp[i] = 1 + dp[prev];
                    parent[i] = prev;
                }
            }

            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        vector<int> lis;

        while (parent[lastIndex] != lastIndex) {
            lis.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }

        lis.push_back(nums[lastIndex]);

        reverse(lis.begin(), lis.end());

        // Print LIS
        for (int x : lis) {
            cout << x << " ";
        }

        return maxi;
    }
};
