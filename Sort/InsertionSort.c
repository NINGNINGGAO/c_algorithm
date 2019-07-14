<<<<<<< Updated upstream
int* InsertionSort(int* nums, int numsSize) {
=======
#include <stdio.h>

void InsertionSort(int* nums, int numsSize) {
>>>>>>> Stashed changes
    int i, j, temp;
    for (i = 0; i < numsSize; i++) {
        temp = nums[i];
        for (j = i - 1; j >= 0 && nums[j] > temp; j--) {
            nums [j + 1] = nums[j];
        }
        nums[j+1] = temp;
    }
<<<<<<< Updated upstream
    return nums;
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3};
    int numsSize = sizeof(nums)/sizeof(int);
    //printf("%d\n", numsSize);
    int* p = InsertionSort(nums, numsSize);
    while (*p != '\0') {
        printf("%d\n",*p);
        p++;
=======
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0};
    int numsSize = sizeof(nums) / sizeof(int);
    InsertionSort(nums, numsSize);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
>>>>>>> Stashed changes
    }
}