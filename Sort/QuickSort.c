/*
 * @Author: AGOGIN
 * @Date: 2019-07-28 16:08:51
 * @Last Modified by:   AGOGIN
 * @Last Modified time: 2019-07-28 16:08:51
 */
#include <stdio.h>

void QuickSort(int* nums, int begin, int end) {
    if (begin >= end) return;
    int p = begin, q = end;
    int temp = nums[p];
    while (p < q) {
        while (p < q && nums[q] >= temp) q--;
        if (p < q) nums[p] = nums[q];
        while (p < q && nums[p] < temp) p++;
        if (p < q) nums[q] = nums[p];
    }
    nums[p] = temp;
    QuickSort(nums, begin, p - 1);
    QuickSort(nums, p + 1, end);
}

main() {
    int nums[] = {7,8,9,4,5,6,1,2,3,0,17,18,19,14,15,16,11,12,13,10};
    int numsSize = sizeof(nums) / sizeof(int);
    QuickSort(nums, 0,numsSize - 1);
    for (int i = 0; i < numsSize; i++) {
        printf("%d\n", nums[i]);
    }
}