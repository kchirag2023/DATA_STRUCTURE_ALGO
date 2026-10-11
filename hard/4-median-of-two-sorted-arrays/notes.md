# 4. Median of Two Sorted Arrays

## cpp — v1 (2026-10-11)

- Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
- Time complexity: _not specified_
- Space complexity: _not specified_
- Solution file: [`cpp_v1.cpp`](./cpp_v1.cpp)

// Approach: Binary search on the smaller array; partition both arrays so the left half has (m+n+1)/2 elements.Mid1 number of elemnt from nums1 , (m+n+1)/2 -mid1 number of element from nums2 .
Mistake:



int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];
// Mistakes: Handle boundary cases using INT_MIN/INT_MAX to avoid out-of-bounds access; use mid1 (not mid/px), update low/high correctly, and calculate even median as (max(l1,l2) + min(r1,r2))/2.0.
// Time: O(log(min(m,n))), Space: O(1).

---
