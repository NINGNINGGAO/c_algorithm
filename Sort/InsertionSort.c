/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:45 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:45 
 */
#include <stdio.h>

void InsertionSort(int* nums, int p, int q) {
    int key;
    for (int j = p + 1; j <= q; j++) {
        key = nums[j];
        int i = j - 1;
        while (i >= p && nums[i] > key) {
            nums[i + 1] = nums[i];
            i = i - 1;
        }
        nums[i + 1] = key;
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    InsertionSort(nums, 1, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}