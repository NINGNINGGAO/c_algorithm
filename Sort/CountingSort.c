/*
 * @Author: AGOGIN 
 * @Date: 2019-07-28 16:08:39 
 * @Last Modified by:   AGOGIN 
 * @Last Modified time: 2019-07-28 16:08:39 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CountingSort(int* nums, int p, int q) {
          int  numsmin = nums[p], numsmax = nums[p];
          for (int i = p; i <= q; i++) {
                    if (nums[i] > numsmax) {
                              numsmax = nums[i];
                    }
                    if (nums[i] < numsmin) {
                              numsmin = nums[i];
                    }
          }
          int numslength = numsmax - numsmin + 1;
          int* C = malloc(sizeof(int) * numslength);
          memset(C, 0, numslength);
          for (int j = p; j <= q; j++) {
                    C[nums[j] - numsmin]++;
          }
          for (int k = 1; k < numslength; k++) {
                    C[k] = C[k] + C[k - 1];
          }
          int* numsSort = malloc(sizeof(int) * (q - p + 1));
          for (int h = q; h >= p; h--) {
                    numsSort[C[nums[h] - numsmin] - 1] = nums[h];
                    C[nums[h] - numsmin]--;
          }
          for (int i = p; i <= q; i++) {
                    nums[i] = numsSort[i - p];
          }
}

main() {
          int nums[] = {11,3,4,5,6,7,8,9,15,16};
          int numsSize = sizeof(nums) / sizeof(int);
          CountingSort(nums, 1, numsSize - 1);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", nums[i]);
          }
}