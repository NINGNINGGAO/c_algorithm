#include <stdio.h>

void InsertionSort(int* nums, int numsSize) {
    int i, j, temp;
    for (i = 0; i < numsSize; i++) {
        temp = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
            nums [j + 1] = nums[j];
        }
        nums[j+1] = temp;
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    InsertionSort(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}