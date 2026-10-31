// Pushed: 2026-10-31 04:35:14 UTC
// Difficulty: Easy
// Runtime: 2 ms
// Memory: 14.9 MB

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];

            if(mp.find(rem) != mp.end()) {
                return {mp[rem], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};