#include <stdio.h>


int* BubbleSort(int* nums, int numsSize) {
    int i, j, temp;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = 0; j < numsSize - 1 - i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3};
    int numsSize = sizeof(nums)/sizeof(int);
    //printf("%d\n", numsSize);
    int* p = BubbleSort(nums, numsSize);
    while (*p != '\0') {
        printf("%d\n",*p);
        p++;
    }
}