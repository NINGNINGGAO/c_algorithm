#include <stdio.h>

<<<<<<< Updated upstream

int* BubbleSort(int* nums, int numsSize) {
=======
void BubbleSort(int* nums, int numsSize) {
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
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
=======
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    BubbleSort(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
>>>>>>> Stashed changes
    }
}