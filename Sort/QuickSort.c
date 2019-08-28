/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:51 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:51 
 */
#include <stdio.h>

int partition(int* nums, int p, int r) {
          int x = nums[r];
          int i = p - 1;
          int temp;
          for (int j = p; j < r; j++) {
                    if (nums[j] <= x) {
                              i = i + 1;
                              temp = nums[i];
                              nums[i] = nums[j];
                              nums[j] = temp;
                    }
          }
          nums[r] = nums[i + 1];
          nums[i + 1] = x;
          return i + 1;
}

void Quick(int* nums, int p, int r) {
          if (p < r) {
                    int q = partition(nums, p, r);
                    Quick(nums, p, q - 1);
                    Quick(nums, q, r);
          }
}

main() {
          int nums[] = {7,8,9,4,5,6,1,2,3,0,17,18,19,14,15,16,11,12,13,10};
          int numsSize = sizeof(nums) / sizeof(int);
          Quick(nums, 1,numsSize - 1);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}