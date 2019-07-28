/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:57 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:57 
 */
#include <stdio.h>
#include <stdlib.h>

int pow(int x, int y) {
          int res = 1;
          for (int i = 0; i < y; i++) {
                    res *= x;
          }
          return res;
}

int maxbit(int* nums, int numsSize) {
          int digit = 0;
          int temp = 1;
          while (temp != 0) {
                    temp = 0;
                    for (int i = 0; i < numsSize; i++) {
                              temp += (nums[i] / pow(10, (digit + 1)));
                    }
          digit++;
          }
          return digit;
} 


void CountingSort(int* nums, int numsSize, int* part) {
          int numslength = 10;
          int* C = (int*)calloc(sizeof(int), numslength);
          for (int j = 0; j < numsSize; j++) {
                    C[part[j]]++;
          }
          for (int k = 1; k < numslength; k++) {
                    C[k] = C[k] + C[k - 1];
          }
          int* numsSort = (int*)malloc(sizeof(int) * numsSize);
          for (int h = numsSize - 1; h >= 0; h--) {
                    numsSort[C[part[h]] - 1] = nums[h];
                    C[part[h]]--;
          }
          for (int i = 0; i < numsSize; i++) {
                    nums[i] = numsSort[i];
          }
}

void RadixSort(int* nums, int numsSize) {
          int digit = maxbit(nums, numsSize);
          int *part = (int*)malloc(sizeof(int) * numsSize);
          for (int i = 1; i <= digit; i++) {
                    for (int j = 0; j < numsSize; j++) {
                              part[j] = nums[j] / pow(10, i - 1);
                              part[j] = part[j] % 10;
                    }
                    CountingSort(nums, numsSize, part);
          }
}

main() {
          int nums[] = {17,18,19,14,15,16,11,12,13,10,9,29,38,111,0,11119};
          int numsSize = sizeof(nums) / sizeof(int);
          RadixSort(nums, numsSize);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}