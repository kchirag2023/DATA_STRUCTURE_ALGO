// Pushed: 2026-11-02 19:52:03 UTC
// Difficulty: Medium
// Runtime: 204 ms
// Memory: 183.4 MB

// ## What is a Segment Tree?

// A Segment Tree is a binary tree data structure used to store information about different intervals (segments) of an array.

// It is commonly used to answer range queries such as:
// - Range Sum Query
// - Range Minimum Query
// - Range Maximum Query
// - Range GCD Query

// It also supports efficient updates to array elements.

// Time Complexity:
// - Build: O(n)
// - Range Query: O(log n)
// - Point Update: O(log n)

// Compared to a brute-force approach, which may take O(n) per query, a Segment Tree provides much faster range queries and updates.

// ## Key Characteristics

// 1. Root Node:
//    - Represents the entire array range [0, n-1].

// 2. Child Nodes:
//    - Each node divides its range into two halves.
//    - Left child represents [low, mid].
//    - Right child represents [mid+1, high].
//    - mid = (low + high) / 2.

// 3. Leaf Nodes:
//    - Represent individual elements of the array.
//    - Each leaf corresponds to a range of size 1.

// 4. Storage:
//    - A Segment Tree is generally implemented using an array.
//    - We usually allocate an array of size 4*n to store the tree.

// 5. Child Indexing (0-based indexing):
//    - Left Child = 2*i + 1
//    - Right Child = 2*i + 2

// ## Advantages

// - Efficient range queries.
// - Efficient point updates.
// - Supports different operations like SUM, MIN, MAX and GCD.
// - Can be extended to support lazy propagation for efficient range updates.


#include <bits/stdc++.h>
using namespace std;

class NumArray {
public:
    vector<int> arr;
    vector<int> seg;
    int n;

    // 1. Build Segment Tree
    void build(int index, int low, int high) {
        if (low == high) {
            seg[index] = arr[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * index + 1, low, mid);
        build(2 * index + 2, mid + 1, high);

        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    // 2. Query: Sum of range [l, r]
    int query(int index, int low, int high, int l, int r) {
        // Complete Overlap
        if (low >= l && high <= r) {
            return seg[index];
        }

        // No Overlap
        if (high < l || low > r) {
            return 0;
        }

        // Partial Overlap
        int mid = low + (high - low) / 2;

        int left = query(2 * index + 1, low, mid, l, r);
        int right = query(2 * index + 2, mid + 1, high, l, r);

        return left + right;
    }

    // 3. Update: Change arr[pos] to val
    void updateTree(int index, int low, int high, int pos, int val) {
        if (low == high) {
            seg[index] = val;
            arr[pos] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (pos <= mid) {
            updateTree(2 * index + 1, low, mid, pos, val);
        }
        else {
            updateTree(2 * index + 2, mid + 1, high, pos, val);
        }

        // Recalculate current node
        seg[index] = seg[2 * index + 1] + seg[2 * index + 2];
    }

    // Constructor
    NumArray(vector<int>& nums) {
        arr = nums;
        n = nums.size();

        seg.resize(4 * n);

        if (n > 0) {
            build(0, 0, n - 1);
        }
    }

    // Public Update Function
    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    // Public Range Sum Function
    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */