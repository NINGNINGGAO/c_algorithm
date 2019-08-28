/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:09:01 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:09:01 
 */
#include <stdio.h>

void SelectionSort(int* nums, int p, int q) {
    int i, j, k, temp;
    for (i = p; i < q; i++) {
        k = i;
        for (j = i + 1; j <= q; j++) {
            if (nums[j] < nums[k]) {
                k = j;
            }
        }
        temp = nums[i];
        nums[i] = nums[k];
        nums[k] = temp;
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    SelectionSort(nums, 1, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}