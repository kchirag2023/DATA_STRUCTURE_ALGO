# 152. Maximum Product Subarray

## cpp — v1 (2026-10-31)

- Problem: https://leetcode.com/problems/maximum-product-subarray/
- Time complexity: _not specified_
- Space complexity: _not specified_
- Solution file: [`cpp_v1.cpp`](./cpp_v1.cpp)

// A) IF ALL ELEMENT IS EVEN THEN-> ALL ARRAY PRODUCT IS ANSWER
        // B)IF EVEN NO. NEGATIVE->ALL ARRAY IS ANSWER
        // C) IF ODD NO. OF NEGATIVE-> WE HAVE TO TAKE EVEN NUMBER OF NEGATIVE-> WE HAVE TO CHECK WETHER TAKE NEGATIVES FROM LEFT SIDE OR RIGHT
        // D) DURING ZER0-> IGNORE ZERO ,UPDATE MAX PREFIX PRODUCT=1, NO CHANGE TO MAX PRODUCT.

---
