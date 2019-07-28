/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:09:04 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:09:04 
 */
#include <stdio.h>

void ShellSort_1(int* nums, int numsSize) {
    int i, j, temp;
    int* p;
    int interval[] = {		// Sedgewick增量
          1073643521, 603906049, 268386305, 150958081, 67084289,
          37730305, 16764929, 9427969, 4188161, 2354689,
          1045505, 587521, 260609, 146305, 64769,
          36289, 16001, 8929, 3905, 2161,
          929, 505, 209, 109, 41,
          19, 5, 1, 0};
    for (p = interval; *p > numsSize; p++);
    while (*p != 0) {
        for (i = *p; i < numsSize; i++) {
            temp = nums[i];
            for (j = i - *p; j >= 0 && nums[j] > temp; j -= *p) {
                nums[j + *p] = nums[j];
                nums[j] = temp;
            }
        }
        p++;
    }
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0,19,18,17,14,15,16,11,12,13,10,27,28,29,24,25,26,21,22,23,20};
    int numsSize = sizeof(nums) / sizeof(int);
    ShellSort_1(nums,numsSize);
    int i;
    for (i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}