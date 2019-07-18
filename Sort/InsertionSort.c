#include <stdio.h>

void InsertionSort(int* nums, int numsSize) {
    int key;
    for (int j = 1; j < numsSize; j++) {
        key = nums[j];
        int i = j - 1;
        while (i >= 0 && nums[i] > key) {
            nums[i + 1] = nums[i];
            i = i - 1;
        }
        nums[i + 1] = key;
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