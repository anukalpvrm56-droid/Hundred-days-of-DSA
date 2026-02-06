#include <stdio.h>

int main() {
    int nums[100];
    int numsSize;

    scanf("%d", &numsSize);
    for (int i = 0; i < numsSize; i++) {
        scanf("%d", &nums[i]);
    }

    int k = 0;   // index for next non-zero

    // move non-zero elements forward
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            
            nums[k] = nums[i];
            k++;
        }
    }

    // fill remaining positions with 0
    while (k < numsSize) {
        nums[k++] = 0;
    }

    // print result
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
