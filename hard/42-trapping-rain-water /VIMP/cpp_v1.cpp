// Pushed: 2026-11-02 16:44:42 UTC
// Difficulty: Hard
// Runtime: 2 ms
// Memory: 26.9 MB

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
    if (n <= 2) return 0;
    
    stack<int> st;
    int water = 0;
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int bottom = st.top();
            st.pop();
            
            // If there is no left boundary, we cannot trap water
            if (st.empty()) {
                break;
            }
            
            int left = st.top();
            int width = i - left - 1;
            int bounded_height = min(height[left], height[i]) - height[bottom];
            
            water += width * bounded_height;
        }
        st.push(i);
    }
    
    return water;
        
    }
};