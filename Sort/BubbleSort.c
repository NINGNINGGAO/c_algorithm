/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:32 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:32 
 */
#include <stdio.h>

void BubbleSort(int* nums, int p, int q) {
    int i, j, temp;
    for (i = p; i < q; i++) {
        for (j = p; j < q - i; j++) {
            if (nums[j] > nums[j+1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0, 10};
    int numsSize = sizeof(nums) / sizeof(int);
    BubbleSort(nums, 1, numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}