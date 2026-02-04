#include <stdio.h>

int main() {
    int nums[100];   // array to store elements
    int n;           // size of array
    int val;         // value to be removed
    int k = 0;       // count of elements not equal to val

    // Read number of elements
    scanf("%d", &n);

    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    // Read the value that needs to be removed
    scanf("%d", &val);

    /*
       Traverse the array.
       If the current element is NOT equal to val,
       store it at index k and increment k.
       This shifts all valid elements to the front.
    */
    for (int i = 0; i < n; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    // Print the number of valid elements
    printf("%d\n", k);

    // Print the first k elements of the modified array
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
