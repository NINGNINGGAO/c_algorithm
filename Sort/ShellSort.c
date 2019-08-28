/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:09:11 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:09:11 
 */
#include <stdio.h>

void ShellSort(int* nums, int p, int q) {
    int numsSize = q - p + 1;
    int i, j, temp, interval;
    for (interval = numsSize >> 1; interval > 0; interval >>= 1) {
        for (i = interval + p; i < numsSize + p; i++) {
            temp = nums[i];
            for (j = i - interval; j >= p && nums[j] > temp; j -= interval) {
                nums[j + interval] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    ShellSort(nums,1, numsSize - 1);
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}