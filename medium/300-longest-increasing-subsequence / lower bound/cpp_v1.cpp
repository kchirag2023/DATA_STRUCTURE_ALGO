// Pushed: 2026-11-02 15:19:48 UTC
// Difficulty: Medium
// Runtime: 1 ms
// Memory: 14 MB

class Solution {
public:
   
    int lengthOfLIS(vector<int>& arr) {
        vector<int> temp;
        
        for (int i = 0; i < arr.size(); i++) {
            // Find the first element in temp that is greater than or equal to arr[i]
            auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
            
            // If arr[i] is greater than all elements in temp, append it
            if (it == temp.end()) {
                temp.push_back(arr[i]);
            } 
            // Otherwise, replace the existing element to keep potential future values smaller
            else {
                *it = arr[i];
            }
        }
        
        // The size of temp represents the length of the longest increasing subsequence
        return temp.size();
    }
        
    
};