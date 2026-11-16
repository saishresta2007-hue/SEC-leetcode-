#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size,
                              int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size,
                                      nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int left = 0, right = m;

    while (left <= right) {
        int cut1 = left + (right - left) / 2;
        int cut2 = (m + n + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int r1 = (cut1 == m) ? INT_MAX : nums1[cut1];

        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r2 = (cut2 == n) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1) {
            if ((m + n) % 2 == 0) {
                int leftMax = (l1 > l2) ? l1 : l2;
                int rightMin = (r1 < r2) ? r1 : r2;
                return (leftMax + rightMin) / 2.0;
            } else {
                return (double)((l1 > l2) ? l1 : l2);
            }
        } else if (l1 > r2) {
            right = cut1 - 1;
        } else {
            left = cut1 + 1;
        }
    }

    return 0.0;
}