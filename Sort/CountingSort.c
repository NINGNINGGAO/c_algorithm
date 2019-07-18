#include <stdio.h>
#include <stdlib.h>

void CountingSort(int* nums, int numsSize, int** numsSort) {
          int  numsmin = nums[0], numsmax = nums[0];
          for (int i = 1; i < numsSize; i++) {
                    if (nums[i] > numsmax) {
                              numsmax = nums[i];
                    }
                    if (nums[i] < numsmin) {
                              numsmin = nums[i];
                    }
          }
          int numslength = numsmax - numsmin + 1;
          int* C = (int*)calloc(sizeof(int), numslength);
          for (int j = 0; j < numsSize; j++) {
                    C[nums[j] - numsmin]++;
          }
          for (int k = 1; k < numslength; k++) {
                    C[k] = C[k] + C[k - 1];
          }
          *numsSort = (int*)malloc(sizeof(int) * numsSize);
          for (int h = numsSize - 1; h >= 0; h--) {
                    (*numsSort)[C[nums[h] - numsmin] - 1] = nums[h];
                    C[nums[h] - numsmin]--;
          }
}

main() {
          int* numsSort;
          int nums[] = {7,8,9,4,5,6,2,3};
          int numsSize = sizeof(nums) / sizeof(int);
          CountingSort(nums, numsSize, &numsSort);
          for (int i = 0; i < numsSize; i++) {
                    printf("%d\n", numsSort[i]);
          }
}