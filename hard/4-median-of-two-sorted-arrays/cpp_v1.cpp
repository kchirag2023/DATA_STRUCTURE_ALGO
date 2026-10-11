// Pushed: 2026-10-11 20:50:03 UTC
// Difficulty: Hard
// Runtime: 0 ms
// Memory: 95 MB

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // merge 2 array best approach 
        // O(n+m) type 
        //best optimal 0(log(N+M));

        //WE WIIL LET MEDIAN POINT M, (mid1 number of element from num1,mid22) COME ON THE LEFT SIDE OF M;

        int m = nums1.size();
        int n = nums2.size();

        // Binary search on the smaller array
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int low = 0;
        int high = m;

        while (low <= high) {
            // mid1 number of element from num1 comeing to left of median 
            int mid1 = low + (high - low) / 2;
            int mid2 = (m + n + 1) / 2 - mid1;

            int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
            int r1 = (mid1 == m) ? INT_MAX : nums1[mid1];
            int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
            int r2 = (mid2 == n) ? INT_MAX : nums2[mid2];

            if (l1 <= r2 && l2 <= r1) {
                if ((m + n) % 2 == 1) {
                    return max(l1, l2);
                }
                else {
                    return (max(l1, l2) + (double)min(r1, r2)) / 2.0;
                }
            }
            else if (l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return -1;
    }
};