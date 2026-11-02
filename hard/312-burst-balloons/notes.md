# 312. Burst Balloons

## cpp — v1 (2026-11-02)

- Problem: https://leetcode.com/problems/burst-balloons/
- Time complexity: _not specified_
- Space complexity: _not specified_
- Solution file: [`cpp_v1.cpp`](./cpp_v1.cpp)

1. What does Matrix Chain Multiplication mean?
Suppose you have three matrices:
- A = 10 × 20
- B = 20 × 30
- C = 30 × 40
You want to multiply all three matrices:
\[
A \times B \times C
\]

The important thing is that the order of multiplication can change the number of operations, but the final result remains the same.

For example, there are two ways:

Option 1: (A × B) × C

First multiply A and B:
\[
10 \times 20 \times 30 = 6000
\]

Resulting matrix: 10 × 30.

Now multiply with C:
\[
10 \times 30 \times 40 = 12000
\]

Total operations:
\[
6000+12000=\boxed{18000}
\]

Option 2: A × (B × C)

First multiply B and C:
\[
20 \times 30 \times 40 = 24000
\]

Resulting matrix: 20 × 40.

Now multiply with A:
\[
10 \times 20 \times 40 = 8000
\]

Total operations:
\[
24000+8000=\boxed{32000}
\]

Optimal answer: 18000
So, our objective is to find the minimum number of scalar multiplications. Do smartly we should be muslitpy first to reduce operation

---
