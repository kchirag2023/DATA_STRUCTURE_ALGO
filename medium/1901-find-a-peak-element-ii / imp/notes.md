# 1901. Find a Peak Element II

## cpp — v1 (2026-11-02)

- Problem: https://leetcode.com/problems/find-a-peak-element-ii/
- Time complexity: O(nlogm)
- Space complexity: _not specified_
- Solution file: [`cpp_v1.cpp`](./cpp_v1.cpp)

first find max value in mid column , then elimante right or left matrix part based on comparison of(mid+1,mid-1). then short the search space.
one thing more , here peak-> an elemnt greter then its left , right, top, bottom(4 adjacent elemnet).

---
