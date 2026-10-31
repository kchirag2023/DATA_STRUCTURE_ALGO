// Pushed: 2026-10-31 13:56:16 UTC
// Difficulty: Medium
// Runtime: 22 ms
// Memory: 17.3 MB


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        // max we can go for 3 loop(2 loop+ 2pointer) 
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for (int i = 0; i < n - 3; i++) {

            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            for (int j = i + 1; j < n - 2; j++) {

                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                int low = j + 1;
                int high = n - 1;

                while (low < high) {

                    long long sum = (long long)nums[i] +
                                    nums[j] + nums[low] + nums[high];

                    if (sum > target) {
                        high--;
                    }
                    else if (sum < target) {
                        low++;
                    }
                    else {
                        ans.push_back({
                            nums[i], nums[j], nums[low], nums[high]
                        });

                        int temp1 = nums[low];
                        int temp2 = nums[high];

                        while (low < high && nums[low] == temp1)
                            low++;

                        while (low < high && nums[high] == temp2)
                            high--;
                    }
                }
            }
        }

        return ans;
    }
};
