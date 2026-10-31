// Pushed: 2026-10-31 07:52:25 UTC
// Difficulty: Medium
// Runtime: 84 ms
// Memory: 29.2 MB

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int high=n-1;
            int low=i+1;
            while(low<high && high<n && low<n){
                if(nums[i]+nums[low]+nums[high]<0){
                    low++;

                }
                else if(nums[i]+nums[low]+nums[high]>0){
                    high--;

                }
                else{
                   
                    ans.push_back({nums[i],nums[low],nums[high]});
                      int tempIndex1 = low, tempIndex2 = high;
                    while(low < high && nums[low] == nums[tempIndex1]) low++;
                    while(low < high && nums[high] == nums[tempIndex2]) high--;

                }
                while(i+1 < n && nums[i] == nums[i+1]) i++;
            }
        }
        return ans;
    }
};