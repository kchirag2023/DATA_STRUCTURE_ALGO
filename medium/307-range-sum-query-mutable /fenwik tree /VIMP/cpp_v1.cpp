// Pushed: 2026-11-02 19:26:55 UTC
// Difficulty: Medium
// Runtime: 141 ms
// Memory: 180.2 MB

// How the Stored Range is Defined
// For any index i (using 1-based indexing):

// Length of the range: The number of elements stored at index i is determined by its lowest set bit, i & -i.

// Range boundaries: Index i stores the sum of elements starting from index i - (i & -i) + 1 up to i.

// #include <bits/stdc++.h>
// using namespace std;

// class FenwickTree {
//     int n;
//     vector<int> bit;

// public:
//     FenwickTree(int size) {
//         n = size;
//         bit.assign(n + 1, 0); // 1-based indexing
//     }

//     // 1. Update Operation: adds 'val' at index 'i' in O(log N)
//     void update(int i, int val) {
//         while (i <= n) {
//             bit[i] += val;
//             i += (i & -i); // Move to the next affected index
//         }
//     }

//     // 2. Prefix Sum Query: returns sum from index 1 to 'i' in O(log N)
//     int query(int i) {
//         int sum = 0;
//         while (i > 0) {
//             sum += bit[i];
//             i -= (i & -i); // Move to the parent node by turning off the rightmost set bit
//         }
//         return sum;
//     }

//     // 3. Range Sum Query: returns sum between range [l, r]
//     int rangeSum(int l, int r) {
//         return query(r) - query(l - 1);
//     }
class NumArray {
private:
    int n;
    vector<int> bit;
    vector<int> nums;

    // Internal function to add 'val' to index 'i' in the BIT
    void add(int i, int val) {
        for (; i <= n; i += (i & -i)) {
            bit[i] += val;
        }
    }

    // Internal function to get prefix sum from 1 to 'i'
    int query(int i) {
        int sum = 0;
        for (; i > 0; i -= (i & -i)) {
            sum += bit[i];
        }
        return sum;
    }

public:
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        bit.assign(n + 1, 0); // 1-based indexing for BIT
        
        // Populate the BIT with initial array values
        for (int i = 0; i < n; ++i) {
            add(i + 1, nums[i]);
        }
    }
    
    void update(int index, int val) {
        // Calculate the difference between the new value and old value
        int diff = val - nums[index];
        nums[index] = val; // Update the local copy
        
        // Update the Fenwick Tree using 1-based indexing (index + 1)
        add(index + 1, diff);
    }
    
    int sumRange(int left, int right) {
        // Range sum [left, right] in 0-based indexing translates to 
        // query(right + 1) - query(left) in 1-based Fenwick Tree indexing
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */