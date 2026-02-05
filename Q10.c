// Leetcode question Q88 
#include <stdio.h>

int main() {
    int m, n;

    // Input m
    scanf("%d", &m);

    // nums1 has size m + n, but n is not known yet
    int nums1[100];   // assume enough size

    // Input first m elements
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Input n
    scanf("%d", &n);

    // Remaining positions are zeros
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    int nums2[100];

    // Input nums2
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    // In-place merge from the back
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    // Copy remaining nums2 elements if any
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }

    // Output final merged array
    for (int x = 0; x < m + n; x++) {
        printf("%d ", nums1[x]);
    }

    return 0;
}
