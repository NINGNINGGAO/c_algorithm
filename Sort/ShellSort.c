#include <stdio.h>

void ShellSort(int* nums, int numsSize) {
    int i, j, temp, interval;
    for (interval = numsSize >> 1; interval > 0; interval >>= 1) {
        for (i = interval; i < numsSize; i++) {
            temp = nums[i];
            for (j = i - interval; j >= 0 && nums[j] > temp; j -= interval) {
                nums[j + interval] = nums[j];
                nums[j] = temp;
            }
        }
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    ShellSort(nums,numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}